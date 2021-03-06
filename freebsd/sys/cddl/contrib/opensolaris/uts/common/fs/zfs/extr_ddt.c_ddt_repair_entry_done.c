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
struct TYPE_3__ {int /*<<< orphan*/ * io_private; } ;
typedef  TYPE_1__ zio_t ;
typedef  int /*<<< orphan*/  ddt_entry_t ;

/* Variables and functions */
 int /*<<< orphan*/  ddt_free (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
ddt_repair_entry_done(zio_t *zio)
{
	ddt_entry_t *rdde = zio->io_private;

	ddt_free(rdde);
}