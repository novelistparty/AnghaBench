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
struct radius_session {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  srv_log (struct radius_session*,char*,char const*) ; 

__attribute__((used)) static void radius_server_log_msg(void *ctx, const char *msg)
{
	struct radius_session *sess = ctx;
	srv_log(sess, "EAP: %s", msg);
}