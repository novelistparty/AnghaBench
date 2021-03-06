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
 int /*<<< orphan*/  CRYPTO_THREAD_lock_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * sec_malloc_lock ; 
 scalar_t__ secure_mem_initialized ; 
 scalar_t__ secure_mem_used ; 
 int /*<<< orphan*/  sh_done () ; 

int CRYPTO_secure_malloc_done(void)
{
#ifdef OPENSSL_SECURE_MEMORY
    if (secure_mem_used == 0) {
        sh_done();
        secure_mem_initialized = 0;
        CRYPTO_THREAD_lock_free(sec_malloc_lock);
        sec_malloc_lock = NULL;
        return 1;
    }
#endif /* OPENSSL_SECURE_MEMORY */
    return 0;
}