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
typedef  int /*<<< orphan*/  user ;
typedef  int /*<<< orphan*/  rating ;

/* Variables and functions */
 int /*<<< orphan*/  check (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/ * user_get_object_rating (int /*<<< orphan*/ *,int,int) ; 

rating user_get_object_weight (user *u, int local_id, int num) {
  check (u, local_id);

  return *user_get_object_rating (u, local_id, num);
}