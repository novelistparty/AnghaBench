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
struct rrdengine_instance {int dummy; } ;

/* Variables and functions */
 int init_data_files (struct rrdengine_instance*) ; 

int init_rrd_files(struct rrdengine_instance *ctx)
{
    return init_data_files(ctx);
}