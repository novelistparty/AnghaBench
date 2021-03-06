#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  const* policy_id; } ;
typedef  TYPE_1__ TS_REQ ;
typedef  int /*<<< orphan*/  const ASN1_OBJECT ;

/* Variables and functions */
 int /*<<< orphan*/  ASN1_OBJECT_free (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  ERR_R_MALLOC_FAILURE ; 
 int /*<<< orphan*/  const* OBJ_dup (int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  TS_F_TS_REQ_SET_POLICY_ID ; 
 int /*<<< orphan*/  TSerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

int TS_REQ_set_policy_id(TS_REQ *a, const ASN1_OBJECT *policy)
{
    ASN1_OBJECT *new_policy;

    if (a->policy_id == policy)
        return 1;
    new_policy = OBJ_dup(policy);
    if (new_policy == NULL) {
        TSerr(TS_F_TS_REQ_SET_POLICY_ID, ERR_R_MALLOC_FAILURE);
        return 0;
    }
    ASN1_OBJECT_free(a->policy_id);
    a->policy_id = new_policy;
    return 1;
}