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
typedef  int /*<<< orphan*/  uint8_t ;
struct uECC_Curve_t {int dummy; } ;
typedef  int /*<<< orphan*/  public_computed ;
typedef  int /*<<< orphan*/  public ;
typedef  int /*<<< orphan*/  private ;

/* Variables and functions */
 int /*<<< orphan*/  fflush (int /*<<< orphan*/ ) ; 
 scalar_t__ memcmp (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  stdout ; 
 int uECC_compute_public_key (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct uECC_Curve_t const*) ; 
 int /*<<< orphan*/  uECC_make_key (int /*<<< orphan*/ *,int /*<<< orphan*/ *,struct uECC_Curve_t const*) ; 
 struct uECC_Curve_t* uECC_secp160r1 () ; 
 struct uECC_Curve_t* uECC_secp192r1 () ; 
 struct uECC_Curve_t* uECC_secp224r1 () ; 
 struct uECC_Curve_t* uECC_secp256k1 () ; 
 struct uECC_Curve_t* uECC_secp256r1 () ; 
 int /*<<< orphan*/  vli_print (char*,int /*<<< orphan*/ *,int) ; 

int main() {
    int i;
    int success;
    uint8_t private[32];
    uint8_t public[64];
    uint8_t public_computed[64];
    
    int c;
    
    const struct uECC_Curve_t * curves[5];
    int num_curves = 0;
#if uECC_SUPPORTS_secp160r1
    curves[num_curves++] = uECC_secp160r1();
#endif
#if uECC_SUPPORTS_secp192r1
    curves[num_curves++] = uECC_secp192r1();
#endif
#if uECC_SUPPORTS_secp224r1
    curves[num_curves++] = uECC_secp224r1();
#endif
#if uECC_SUPPORTS_secp256r1
    curves[num_curves++] = uECC_secp256r1();
#endif
#if uECC_SUPPORTS_secp256k1
    curves[num_curves++] = uECC_secp256k1();
#endif

    printf("Testing 256 random private key pairs\n");
    for (c = 0; c < num_curves; ++c) {
        for (i = 0; i < 256; ++i) {
            printf(".");
            fflush(stdout);
            
            memset(public, 0, sizeof(public));
            memset(public_computed, 0, sizeof(public_computed));
            
            if (!uECC_make_key(public, private, curves[c])) {
                printf("uECC_make_key() failed\n");
                continue;
            }

            if (!uECC_compute_public_key(private, public_computed, curves[c])) {
                printf("uECC_compute_public_key() failed\n");
            }

            if (memcmp(public, public_computed, sizeof(public)) != 0) {
                printf("Computed and provided public keys are not identical!\n");
                vli_print("Computed public key = ", public_computed, sizeof(public_computed));
                vli_print("Provided public key = ", public, sizeof(public));
                vli_print("Private key = ", private, sizeof(private));
            }
        }
        
        printf("\n");
        printf("Testing private key = 0\n");

        memset(private, 0, sizeof(private));
        success = uECC_compute_public_key(private, public_computed, curves[c]);
        if (success) {
            printf("uECC_compute_public_key() should have failed\n");
        }
        printf("\n");
    }
    
    return 0;
}