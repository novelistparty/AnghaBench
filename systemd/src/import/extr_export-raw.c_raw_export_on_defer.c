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
typedef  int /*<<< orphan*/  sd_event_source ;
typedef  int /*<<< orphan*/  RawExport ;

/* Variables and functions */
 int raw_export_process (int /*<<< orphan*/ *) ; 

__attribute__((used)) static int raw_export_on_defer(sd_event_source *s, void *userdata) {
        RawExport *i = userdata;

        return raw_export_process(i);
}