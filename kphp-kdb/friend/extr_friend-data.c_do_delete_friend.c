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
struct lev_generic {int dummy; } ;
struct lev_del_friend {int friend_id; } ;

/* Variables and functions */
 int /*<<< orphan*/  LEV_FR_DEL_FRIEND ; 
 struct lev_del_friend* alloc_log_event (int /*<<< orphan*/ ,int,int) ; 
 int change_friend_logevent (struct lev_generic*) ; 
 scalar_t__ conv_uid (int) ; 

int do_delete_friend (int user_id, int friend_id) {
  struct lev_del_friend *E;

  if (conv_uid (user_id) < 0 || friend_id <= 0) {
    return -1;
  }

  E = alloc_log_event (LEV_FR_DEL_FRIEND, 12, user_id);
  E->friend_id = friend_id;

  return change_friend_logevent ((struct lev_generic *) E);
}