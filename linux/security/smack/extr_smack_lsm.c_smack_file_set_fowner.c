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
struct smack_known {int dummy; } ;
struct file {int dummy; } ;

/* Variables and functions */
 struct smack_known** smack_file (struct file*) ; 
 struct smack_known* smk_of_current () ; 

__attribute__((used)) static void smack_file_set_fowner(struct file *file)
{
	struct smack_known **blob = smack_file(file);

	*blob = smk_of_current();
}