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
struct TYPE_3__ {int /*<<< orphan*/ * engine; } ;
typedef  TYPE_1__ PROV_DIGEST ;
typedef  int /*<<< orphan*/  ENGINE ;

/* Variables and functions */

ENGINE *ossl_prov_digest_engine(const PROV_DIGEST *pd)
{
    return pd->engine;
}