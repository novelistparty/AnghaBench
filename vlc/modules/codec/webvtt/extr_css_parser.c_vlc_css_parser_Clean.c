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
struct TYPE_4__ {int /*<<< orphan*/  p_first; } ;
struct TYPE_5__ {TYPE_1__ rules; } ;
typedef  TYPE_2__ vlc_css_parser_t ;

/* Variables and functions */
 int /*<<< orphan*/  vlc_css_rules_Delete (int /*<<< orphan*/ ) ; 

void vlc_css_parser_Clean( vlc_css_parser_t *p_parser )
{
    vlc_css_rules_Delete( p_parser->rules.p_first );
}