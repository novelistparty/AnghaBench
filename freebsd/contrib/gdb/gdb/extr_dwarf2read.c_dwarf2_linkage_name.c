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
struct dwarf2_cu {int dummy; } ;
struct die_info {int dummy; } ;
struct attribute {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  DW_AT_MIPS_linkage_name ; 
 int /*<<< orphan*/  DW_AT_name ; 
 char* DW_STRING (struct attribute*) ; 
 struct attribute* dwarf2_attr (struct die_info*,int /*<<< orphan*/ ,struct dwarf2_cu*) ; 

__attribute__((used)) static char *
dwarf2_linkage_name (struct die_info *die, struct dwarf2_cu *cu)
{
  struct attribute *attr;

  attr = dwarf2_attr (die, DW_AT_MIPS_linkage_name, cu);
  if (attr && DW_STRING (attr))
    return DW_STRING (attr);
  attr = dwarf2_attr (die, DW_AT_name, cu);
  if (attr && DW_STRING (attr))
    return DW_STRING (attr);
  return NULL;
}