#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ q_iter ;
struct TYPE_2__ {void* data; } ;
typedef  TYPE_1__ node ;

/* Variables and functions */
 int False_ ; 
 int True_ ; 

int Q_Iter_Put(q_iter qi, void* data) {
   if(qi) {
      ((node*)qi)->data = data;
      return True_;
   }
   return False_;
}