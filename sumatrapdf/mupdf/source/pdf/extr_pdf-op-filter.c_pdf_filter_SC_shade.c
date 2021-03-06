#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  pdf_processor ;
typedef  int /*<<< orphan*/  pdf_filter_processor ;
typedef  int /*<<< orphan*/  fz_shade ;
typedef  int /*<<< orphan*/  fz_context ;
struct TYPE_5__ {scalar_t__ n; int /*<<< orphan*/ * shd; int /*<<< orphan*/ * pat; int /*<<< orphan*/  name; } ;
struct TYPE_6__ {TYPE_1__ SC; } ;
struct TYPE_7__ {TYPE_2__ pending; } ;
typedef  TYPE_3__ filter_gstate ;

/* Variables and functions */
 int /*<<< orphan*/  PDF_NAME (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  Pattern ; 
 int /*<<< orphan*/  copy_resource (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ,char const*) ; 
 int /*<<< orphan*/  fz_strlcpy (int /*<<< orphan*/ ,char const*,int) ; 
 TYPE_3__* gstate_to_update (int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void
pdf_filter_SC_shade(fz_context *ctx, pdf_processor *proc, const char *name, fz_shade *shade)
{
	pdf_filter_processor *p = (pdf_filter_processor*)proc;
	filter_gstate *gstate = gstate_to_update(ctx, p);
	fz_strlcpy(gstate->pending.SC.name, name, sizeof gstate->pending.SC.name);
	gstate->pending.SC.pat = NULL;
	gstate->pending.SC.shd = shade;
	gstate->pending.SC.n = 0;
	copy_resource(ctx, p, PDF_NAME(Pattern), name);
}