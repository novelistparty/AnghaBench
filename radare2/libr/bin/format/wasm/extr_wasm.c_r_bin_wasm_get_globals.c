#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int /*<<< orphan*/ * g_globals; int /*<<< orphan*/  g_sections; } ;
typedef  int /*<<< orphan*/  RList ;
typedef  int /*<<< orphan*/  RBinWasmSection ;
typedef  TYPE_1__ RBinWasmObj ;

/* Variables and functions */
 int /*<<< orphan*/  R_BIN_WASM_SECTION_GLOBAL ; 
 int /*<<< orphan*/ * r_bin_wasm_get_global_entries (TYPE_1__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * r_bin_wasm_get_sections_by_id (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ r_list_first (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  r_list_free (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * r_list_new () ; 

RList *r_bin_wasm_get_globals (RBinWasmObj *bin) {
	RBinWasmSection *global = NULL;
	RList *globals = NULL;

	if (!bin || !bin->g_sections) {
		return NULL;
	}
	if (bin->g_globals) {
		return bin->g_globals;
	}
	if (!(globals = r_bin_wasm_get_sections_by_id (bin->g_sections, R_BIN_WASM_SECTION_GLOBAL))) {
		return r_list_new ();
	}
	// support for multiple export sections against spec
	if (!(global = (RBinWasmSection *)r_list_first (globals))) {
		r_list_free (globals);
		return r_list_new ();
	}
	bin->g_globals = r_bin_wasm_get_global_entries (bin, global);
	r_list_free (globals);
	return bin->g_globals;
}