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
struct label {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  COUNTER_INC (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  LABEL_CHECK (struct label*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  MAGIC_SOCKET ; 
 int /*<<< orphan*/  socket_copy_label ; 

__attribute__((used)) static void
test_socket_copy_label(struct label *src, struct label *dest)
{

	LABEL_CHECK(src, MAGIC_SOCKET);
	LABEL_CHECK(dest, MAGIC_SOCKET);
	COUNTER_INC(socket_copy_label);
}