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
 scalar_t__ crypto_aead_aes256gcm_is_available () ; 
 int /*<<< orphan*/  printf (char*) ; 
 int /*<<< orphan*/  tv () ; 

int
main(void)
{
    if (crypto_aead_aes256gcm_is_available()) {
        tv();
    }
    printf("OK\n");

    return 0;
}