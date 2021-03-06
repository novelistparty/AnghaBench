#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct r_bin_zimg_obj_t {int /*<<< orphan*/ * kv; } ;
struct TYPE_5__ {TYPE_1__* o; } ;
struct TYPE_4__ {scalar_t__ bin_obj; } ;
typedef  int /*<<< orphan*/  Sdb ;
typedef  TYPE_2__ RBinFile ;

/* Variables and functions */
 int /*<<< orphan*/  r_return_val_if_fail (int,int) ; 

__attribute__((used)) static Sdb *get_sdb(RBinFile *bf) {
	r_return_val_if_fail (bf && bf->o, false);
	struct r_bin_zimg_obj_t *bin = (struct r_bin_zimg_obj_t *) bf->o->bin_obj;
	return bin? bin->kv: NULL;
}