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
typedef  int /*<<< orphan*/ * xsltTransformFunction ;
typedef  int /*<<< orphan*/  xsltPreComputeFunction ;
typedef  TYPE_1__* xsltExtElementPtr ;
typedef  int /*<<< orphan*/  xsltExtElement ;
struct TYPE_3__ {int /*<<< orphan*/ * transform; int /*<<< orphan*/  precomp; } ;

/* Variables and functions */
 scalar_t__ xmlMalloc (int) ; 
 int /*<<< orphan*/  xsltTransformError (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*) ; 

__attribute__((used)) static xsltExtElementPtr
xsltNewExtElement(xsltPreComputeFunction precomp,
                  xsltTransformFunction transform)
{
    xsltExtElementPtr cur;

    if (transform == NULL)
        return (NULL);

    cur = (xsltExtElementPtr) xmlMalloc(sizeof(xsltExtElement));
    if (cur == NULL) {
        xsltTransformError(NULL, NULL, NULL,
                           "xsltNewExtElement : malloc failed\n");
        return (NULL);
    }
    cur->precomp = precomp;
    cur->transform = transform;
    return (cur);
}