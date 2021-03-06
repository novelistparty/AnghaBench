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
typedef  int /*<<< orphan*/  uid_t ;
struct passwd {int dummy; } ;

/* Variables and functions */
 struct passwd* vnextpwent (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

struct passwd *
vgetpwuid(uid_t uid)
{
  return vnextpwent(NULL, uid, 1);
}