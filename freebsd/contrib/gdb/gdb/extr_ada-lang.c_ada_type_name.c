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
struct type {int dummy; } ;

/* Variables and functions */
 char* TYPE_NAME (struct type*) ; 
 char* TYPE_TAG_NAME (struct type*) ; 

char *
ada_type_name (struct type *type)
{
  if (type == NULL)
    return NULL;
  else if (TYPE_NAME (type) != NULL)
    return TYPE_NAME (type);
  else
    return TYPE_TAG_NAME (type);
}