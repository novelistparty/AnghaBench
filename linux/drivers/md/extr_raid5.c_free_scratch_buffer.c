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
struct raid5_percpu {int /*<<< orphan*/ * scribble; int /*<<< orphan*/ * spare_page; } ;
struct r5conf {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  kvfree (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  safe_put_page (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void free_scratch_buffer(struct r5conf *conf, struct raid5_percpu *percpu)
{
	safe_put_page(percpu->spare_page);
	percpu->spare_page = NULL;
	kvfree(percpu->scribble);
	percpu->scribble = NULL;
}