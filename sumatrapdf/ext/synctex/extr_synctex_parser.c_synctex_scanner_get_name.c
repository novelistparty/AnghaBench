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
typedef  TYPE_1__* synctex_scanner_t ;
typedef  int /*<<< orphan*/ * synctex_node_t ;
struct TYPE_3__ {int /*<<< orphan*/ * input; } ;

/* Variables and functions */
 char const* SYNCTEX_NAME (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * SYNCTEX_SIBLING (int /*<<< orphan*/ *) ; 
 int SYNCTEX_TAG (int /*<<< orphan*/ *) ; 

const char * synctex_scanner_get_name(synctex_scanner_t scanner,int tag) {
	synctex_node_t input = NULL;
	if (NULL == scanner) {
		return NULL;
	}
	input = scanner->input;
	do {
		if (tag == SYNCTEX_TAG(input)) {
			return (SYNCTEX_NAME(input));
		}
	} while((input = SYNCTEX_SIBLING(input)) != NULL);
	return NULL;
}