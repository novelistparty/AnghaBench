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
typedef  int /*<<< orphan*/  yrmcds_error ;
struct TYPE_4__ {scalar_t__ text_mode; } ;
typedef  TYPE_1__ yrmcds ;
typedef  int /*<<< orphan*/  uint32_t ;
typedef  int /*<<< orphan*/  key ;

/* Variables and functions */
 int /*<<< orphan*/  YRMCDS_BAD_ARGUMENT ; 
 int /*<<< orphan*/  YRMCDS_CMD_STAT ; 
 int /*<<< orphan*/  YRMCDS_NOT_IMPLEMENTED ; 
 int /*<<< orphan*/  send_command (TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

yrmcds_error yrmcds_stat_settings(yrmcds* c, uint32_t* serial) {
    if( c == NULL )
        return YRMCDS_BAD_ARGUMENT;

    if( c->text_mode )
        return YRMCDS_NOT_IMPLEMENTED;

    const char key[] = "settings";
    return send_command(c, YRMCDS_CMD_STAT,
                        0, serial, sizeof(key) - 1, key, 0, NULL, 0, NULL);
}