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
typedef  struct List* var ;
struct List {int dummy; } ;

/* Variables and functions */
 struct List* List_At (struct List*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  c_int (struct List*) ; 

__attribute__((used)) static var List_Get(var self, var key) {
  struct List* l = self;
  return List_At(l, c_int(key));
}