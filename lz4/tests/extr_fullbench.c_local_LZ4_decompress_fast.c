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
 int /*<<< orphan*/  LZ4_decompress_fast (char const*,char*,int) ; 

__attribute__((used)) static int local_LZ4_decompress_fast(const char* in, char* out, int inSize, int outSize)
{
    (void)inSize;
    LZ4_decompress_fast(in, out, outSize);
    return outSize;
}