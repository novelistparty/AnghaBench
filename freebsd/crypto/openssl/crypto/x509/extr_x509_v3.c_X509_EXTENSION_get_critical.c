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
struct TYPE_3__ {scalar_t__ critical; } ;
typedef  TYPE_1__ X509_EXTENSION ;

/* Variables and functions */

int X509_EXTENSION_get_critical(const X509_EXTENSION *ex)
{
    if (ex == NULL)
        return 0;
    if (ex->critical > 0)
        return 1;
    return 0;
}