#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int number; } ;
struct TYPE_4__ {TYPE_1__ s_number; } ;
struct demangle_component {TYPE_2__ u; int /*<<< orphan*/  type; } ;
struct d_info {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DEMANGLE_COMPONENT_UNNAMED_TYPE ; 
 int /*<<< orphan*/  d_add_substitution (struct d_info*,struct demangle_component*) ; 
 int /*<<< orphan*/  d_check_char (struct d_info*,char) ; 
 int d_compact_number (struct d_info*) ; 
 struct demangle_component* d_make_empty (struct d_info*) ; 

__attribute__((used)) static struct demangle_component *
d_unnamed_type (struct d_info *di)
{
  struct demangle_component *ret;
  int num;

  if (! d_check_char (di, 'U'))
    return NULL;
  if (! d_check_char (di, 't'))
    return NULL;

  num = d_compact_number (di);
  if (num < 0)
    return NULL;

  ret = d_make_empty (di);
  if (ret)
    {
      ret->type = DEMANGLE_COMPONENT_UNNAMED_TYPE;
      ret->u.s_number.number = num;
    }

  if (! d_add_substitution (di, ret))
    return NULL;

  return ret;
}