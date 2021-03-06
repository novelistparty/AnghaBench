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
struct spu_gang {int /*<<< orphan*/  kref; } ;

/* Variables and functions */
 int /*<<< orphan*/  destroy_spu_gang ; 
 int kref_put (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

int put_spu_gang(struct spu_gang *gang)
{
	return kref_put(&gang->kref, &destroy_spu_gang);
}