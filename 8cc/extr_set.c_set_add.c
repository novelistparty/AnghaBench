#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {char* v; struct TYPE_5__* next; } ;
typedef  TYPE_1__ Set ;

/* Variables and functions */
 TYPE_1__* malloc (int) ; 

Set *set_add(Set *s, char *v) {
    Set *r = malloc(sizeof(Set));
    r->next = s;
    r->v = v;
    return r;
}