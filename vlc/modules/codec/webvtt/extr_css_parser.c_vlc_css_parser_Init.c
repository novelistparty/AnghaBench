#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {int /*<<< orphan*/  p_first; int /*<<< orphan*/ * pp_append; } ;
struct TYPE_6__ {TYPE_1__ rules; } ;
typedef  TYPE_2__ vlc_css_parser_t ;

/* Variables and functions */
 int /*<<< orphan*/  memset (TYPE_2__*,int /*<<< orphan*/ ,int) ; 

void vlc_css_parser_Init( vlc_css_parser_t *p_parser )
{
    memset(p_parser, 0, sizeof(vlc_css_parser_t));
    p_parser->rules.pp_append = &p_parser->rules.p_first;
}