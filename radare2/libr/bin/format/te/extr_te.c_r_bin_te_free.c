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
struct r_bin_te_obj_t {int /*<<< orphan*/  b; struct r_bin_te_obj_t* section_header; struct r_bin_te_obj_t* header; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (struct r_bin_te_obj_t*) ; 
 int /*<<< orphan*/  r_buf_free (int /*<<< orphan*/ ) ; 

void* r_bin_te_free(struct r_bin_te_obj_t* bin) {
	if (!bin) {
		return NULL;
	}
	free (bin->header);
	free (bin->section_header);
	r_buf_free (bin->b);
	free (bin);
	return NULL;
}