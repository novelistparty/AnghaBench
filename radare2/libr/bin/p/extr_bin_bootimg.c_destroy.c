#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_8__ {int /*<<< orphan*/  buf; } ;
struct TYPE_7__ {TYPE_1__* o; } ;
struct TYPE_6__ {TYPE_3__* bin_obj; } ;
typedef  TYPE_2__ RBinFile ;
typedef  TYPE_3__ BootImageObj ;

/* Variables and functions */
 int /*<<< orphan*/  R_FREE (TYPE_3__*) ; 
 int /*<<< orphan*/  r_buf_free (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void destroy(RBinFile *bf) {
	BootImageObj *bio = bf->o->bin_obj;
	r_buf_free (bio->buf);
	R_FREE (bf->o->bin_obj);
}