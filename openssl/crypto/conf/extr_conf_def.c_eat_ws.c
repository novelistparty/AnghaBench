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
typedef  int /*<<< orphan*/  CONF ;

/* Variables and functions */
 int /*<<< orphan*/  IS_EOF (int /*<<< orphan*/ *,char) ; 
 scalar_t__ IS_WS (int /*<<< orphan*/ *,char) ; 

__attribute__((used)) static char *eat_ws(CONF *conf, char *p)
{
    while (IS_WS(conf, *p) && (!IS_EOF(conf, *p)))
        p++;
    return p;
}