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

/* Variables and functions */
 scalar_t__ C448_SUCCESS ; 
 scalar_t__ c448_ed448_verify_prehash (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ ) ; 

int ED448ph_verify(const uint8_t hash[64], const uint8_t signature[114],
                   const uint8_t public_key[57], const uint8_t *context,
                   size_t context_len)
{
    return c448_ed448_verify_prehash(signature, public_key, hash, context,
                                     (uint8_t)context_len) == C448_SUCCESS;
}