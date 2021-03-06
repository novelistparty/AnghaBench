#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */

/* Type definitions */

/* Variables and functions */
 int AV_CPU_FLAG_3DNOW ; 
 int AV_CPU_FLAG_3DNOWEXT ; 
 int AV_CPU_FLAG_AESNI ; 
 int AV_CPU_FLAG_ATOM ; 
 int AV_CPU_FLAG_AVX ; 
 int AV_CPU_FLAG_AVX2 ; 
 int AV_CPU_FLAG_AVX512 ; 
 int AV_CPU_FLAG_AVXSLOW ; 
 int AV_CPU_FLAG_BMI1 ; 
 int AV_CPU_FLAG_BMI2 ; 
 int AV_CPU_FLAG_CMOV ; 
 int AV_CPU_FLAG_FMA3 ; 
 int AV_CPU_FLAG_FMA4 ; 
 int AV_CPU_FLAG_MMX ; 
 int AV_CPU_FLAG_MMXEXT ; 
 int AV_CPU_FLAG_SSE ; 
 int AV_CPU_FLAG_SSE2 ; 
 int AV_CPU_FLAG_SSE2SLOW ; 
 int AV_CPU_FLAG_SSE3 ; 
 int AV_CPU_FLAG_SSE3SLOW ; 
 int AV_CPU_FLAG_SSE4 ; 
 int AV_CPU_FLAG_SSE42 ; 
 int AV_CPU_FLAG_SSSE3 ; 
 int AV_CPU_FLAG_SSSE3SLOW ; 
 int AV_CPU_FLAG_XOP ; 
 int /*<<< orphan*/  cpuid (int,int,int,int,int) ; 
 int /*<<< orphan*/  cpuid_test () ; 
 int /*<<< orphan*/  strncmp (char*,char*,int) ; 
 int /*<<< orphan*/  xgetbv (int /*<<< orphan*/ ,int,int) ; 

int ff_get_cpu_flags_x86(void)
{
    int rval = 0;

#ifdef cpuid

    int eax, ebx, ecx, edx;
    int max_std_level, max_ext_level, std_caps = 0, ext_caps = 0;
    int family = 0, model = 0;
    union { int i[3]; char c[12]; } vendor;
    int xcr0_lo = 0, xcr0_hi = 0;

    if (!cpuid_test())
        return 0; /* CPUID not supported */

    cpuid(0, max_std_level, vendor.i[0], vendor.i[2], vendor.i[1]);

    if (max_std_level >= 1) {
        cpuid(1, eax, ebx, ecx, std_caps);
        family = ((eax >> 8) & 0xf) + ((eax >> 20) & 0xff);
        model  = ((eax >> 4) & 0xf) + ((eax >> 12) & 0xf0);
        if (std_caps & (1 << 15))
            rval |= AV_CPU_FLAG_CMOV;
        if (std_caps & (1 << 23))
            rval |= AV_CPU_FLAG_MMX;
        if (std_caps & (1 << 25))
            rval |= AV_CPU_FLAG_MMXEXT;
#if HAVE_SSE
        if (std_caps & (1 << 25))
            rval |= AV_CPU_FLAG_SSE;
        if (std_caps & (1 << 26))
            rval |= AV_CPU_FLAG_SSE2;
        if (ecx & 1)
            rval |= AV_CPU_FLAG_SSE3;
        if (ecx & 0x00000200 )
            rval |= AV_CPU_FLAG_SSSE3;
        if (ecx & 0x00080000 )
            rval |= AV_CPU_FLAG_SSE4;
        if (ecx & 0x00100000 )
            rval |= AV_CPU_FLAG_SSE42;
        if (ecx & 0x02000000 )
            rval |= AV_CPU_FLAG_AESNI;
#if HAVE_AVX
        /* Check OXSAVE and AVX bits */
        if ((ecx & 0x18000000) == 0x18000000) {
            /* Check for OS support */
            xgetbv(0, xcr0_lo, xcr0_hi);
            if ((xcr0_lo & 0x6) == 0x6) {
                rval |= AV_CPU_FLAG_AVX;
                if (ecx & 0x00001000)
                    rval |= AV_CPU_FLAG_FMA3;
            }
        }
#endif /* HAVE_AVX */
#endif /* HAVE_SSE */
    }
    if (max_std_level >= 7) {
        cpuid(7, eax, ebx, ecx, edx);
#if HAVE_AVX2
        if ((rval & AV_CPU_FLAG_AVX) && (ebx & 0x00000020))
            rval |= AV_CPU_FLAG_AVX2;
#if HAVE_AVX512 /* F, CD, BW, DQ, VL */
        if ((xcr0_lo & 0xe0) == 0xe0) { /* OPMASK/ZMM state */
            if ((rval & AV_CPU_FLAG_AVX2) && (ebx & 0xd0030000) == 0xd0030000)
                rval |= AV_CPU_FLAG_AVX512;

        }
#endif /* HAVE_AVX512 */
#endif /* HAVE_AVX2 */
        /* BMI1/2 don't need OS support */
        if (ebx & 0x00000008) {
            rval |= AV_CPU_FLAG_BMI1;
            if (ebx & 0x00000100)
                rval |= AV_CPU_FLAG_BMI2;
        }
    }

    cpuid(0x80000000, max_ext_level, ebx, ecx, edx);

    if (max_ext_level >= 0x80000001) {
        cpuid(0x80000001, eax, ebx, ecx, ext_caps);
        if (ext_caps & (1U << 31))
            rval |= AV_CPU_FLAG_3DNOW;
        if (ext_caps & (1 << 30))
            rval |= AV_CPU_FLAG_3DNOWEXT;
        if (ext_caps & (1 << 23))
            rval |= AV_CPU_FLAG_MMX;
        if (ext_caps & (1 << 22))
            rval |= AV_CPU_FLAG_MMXEXT;

        if (!strncmp(vendor.c, "AuthenticAMD", 12)) {
        /* Allow for selectively disabling SSE2 functions on AMD processors
           with SSE2 support but not SSE4a. This includes Athlon64, some
           Opteron, and some Sempron processors. MMX, SSE, or 3DNow! are faster
           than SSE2 often enough to utilize this special-case flag.
           AV_CPU_FLAG_SSE2 and AV_CPU_FLAG_SSE2SLOW are both set in this case
           so that SSE2 is used unless explicitly disabled by checking
           AV_CPU_FLAG_SSE2SLOW. */
            if (rval & AV_CPU_FLAG_SSE2 && !(ecx & 0x00000040))
                rval |= AV_CPU_FLAG_SSE2SLOW;

        /* Similar to the above but for AVX functions on AMD processors.
           This is necessary only for functions using YMM registers on Bulldozer
           and Jaguar based CPUs as they lack 256-bit execution units. SSE/AVX
           functions using XMM registers are always faster on them.
           AV_CPU_FLAG_AVX and AV_CPU_FLAG_AVXSLOW are both set so that AVX is
           used unless explicitly disabled by checking AV_CPU_FLAG_AVXSLOW. */
            if ((family == 0x15 || family == 0x16) && (rval & AV_CPU_FLAG_AVX))
                rval |= AV_CPU_FLAG_AVXSLOW;
        }

        /* XOP and FMA4 use the AVX instruction coding scheme, so they can't be
         * used unless the OS has AVX support. */
        if (rval & AV_CPU_FLAG_AVX) {
            if (ecx & 0x00000800)
                rval |= AV_CPU_FLAG_XOP;
            if (ecx & 0x00010000)
                rval |= AV_CPU_FLAG_FMA4;
        }
    }

    if (!strncmp(vendor.c, "GenuineIntel", 12)) {
        if (family == 6 && (model == 9 || model == 13 || model == 14)) {
            /* 6/9 (pentium-m "banias"), 6/13 (pentium-m "dothan"), and
             * 6/14 (core1 "yonah") theoretically support sse2, but it's
             * usually slower than mmx, so let's just pretend they don't.
             * AV_CPU_FLAG_SSE2 is disabled and AV_CPU_FLAG_SSE2SLOW is
             * enabled so that SSE2 is not used unless explicitly enabled
             * by checking AV_CPU_FLAG_SSE2SLOW. The same situation
             * applies for AV_CPU_FLAG_SSE3 and AV_CPU_FLAG_SSE3SLOW. */
            if (rval & AV_CPU_FLAG_SSE2)
                rval ^= AV_CPU_FLAG_SSE2SLOW | AV_CPU_FLAG_SSE2;
            if (rval & AV_CPU_FLAG_SSE3)
                rval ^= AV_CPU_FLAG_SSE3SLOW | AV_CPU_FLAG_SSE3;
        }
        /* The Atom processor has SSSE3 support, which is useful in many cases,
         * but sometimes the SSSE3 version is slower than the SSE2 equivalent
         * on the Atom, but is generally faster on other processors supporting
         * SSSE3. This flag allows for selectively disabling certain SSSE3
         * functions on the Atom. */
        if (family == 6 && model == 28)
            rval |= AV_CPU_FLAG_ATOM;

        /* Conroe has a slow shuffle unit. Check the model number to ensure not
         * to include crippled low-end Penryns and Nehalems that lack SSE4. */
        if ((rval & AV_CPU_FLAG_SSSE3) && !(rval & AV_CPU_FLAG_SSE4) &&
            family == 6 && model < 23)
            rval |= AV_CPU_FLAG_SSSE3SLOW;
    }

#endif /* cpuid */

    return rval;
}