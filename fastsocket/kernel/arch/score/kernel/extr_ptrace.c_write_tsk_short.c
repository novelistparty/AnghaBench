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
typedef  int /*<<< orphan*/  val ;
struct task_struct {int dummy; } ;

/* Variables and functions */
 int EIO ; 
 int access_process_vm (struct task_struct*,unsigned long,unsigned short*,int,int) ; 

__attribute__((used)) static int
write_tsk_short(struct task_struct *child,
		unsigned long addr, unsigned short val)
{
	int copied;

	copied = access_process_vm(child, addr, &val, sizeof(val), 1);

	return copied != sizeof(val) ? -EIO : 0;
}