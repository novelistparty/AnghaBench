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
typedef  int /*<<< orphan*/  ShellState ;

/* Variables and functions */
 int /*<<< orphan*/  ShellClearFlag (int /*<<< orphan*/ *,unsigned int) ; 
 int /*<<< orphan*/  ShellSetFlag (int /*<<< orphan*/ *,unsigned int) ; 
 scalar_t__ booleanValue (char const*) ; 

__attribute__((used)) static void setOrClearFlag(ShellState *p, unsigned mFlag, const char *zArg){
  if( booleanValue(zArg) ){
    ShellSetFlag(p, mFlag);
  }else{
    ShellClearFlag(p, mFlag);
  }
}