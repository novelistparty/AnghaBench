#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int uint8_t ;
struct TYPE_8__ {int* tmp; int result_size; unsigned int block_size; int /*<<< orphan*/  (* finish_hash ) (TYPE_1__ const*,int*) ;int /*<<< orphan*/  (* update_hash ) (TYPE_1__ const*,int*,unsigned int) ;int /*<<< orphan*/  (* init_hash ) (TYPE_1__ const*) ;} ;
typedef  TYPE_1__ uECC_HashContext ;

/* Variables and functions */
 int /*<<< orphan*/  stub1 (TYPE_1__ const*,int*) ; 
 int /*<<< orphan*/  stub2 (TYPE_1__ const*) ; 
 int /*<<< orphan*/  stub3 (TYPE_1__ const*,int*,unsigned int) ; 
 int /*<<< orphan*/  stub4 (TYPE_1__ const*,int*,unsigned int) ; 
 int /*<<< orphan*/  stub5 (TYPE_1__ const*,int*) ; 

__attribute__((used)) static void HMAC_finish(const uECC_HashContext *hash_context,
                        const uint8_t *K,
                        uint8_t *result) {
    uint8_t *pad = hash_context->tmp + 2 * hash_context->result_size;
    unsigned i;
    for (i = 0; i < hash_context->result_size; ++i)
        pad[i] = K[i] ^ 0x5c;
    for (; i < hash_context->block_size; ++i)
        pad[i] = 0x5c;

    hash_context->finish_hash(hash_context, result);

    hash_context->init_hash(hash_context);
    hash_context->update_hash(hash_context, pad, hash_context->block_size);
    hash_context->update_hash(hash_context, result, hash_context->result_size);
    hash_context->finish_hash(hash_context, result);
}