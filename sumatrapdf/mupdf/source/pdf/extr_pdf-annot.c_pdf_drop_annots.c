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
struct TYPE_4__ {struct TYPE_4__* next; } ;
typedef  TYPE_1__ pdf_annot ;
typedef  int /*<<< orphan*/  fz_context ;

/* Variables and functions */
 int /*<<< orphan*/  pdf_drop_annot (int /*<<< orphan*/ *,TYPE_1__*) ; 

void
pdf_drop_annots(fz_context *ctx, pdf_annot *annot)
{
	while (annot)
	{
		pdf_annot *next = annot->next;
		pdf_drop_annot(ctx, annot);
		annot = next;
	}
}