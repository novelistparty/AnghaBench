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

/* Variables and functions */
 int /*<<< orphan*/  INIT_LIST_HEAD (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  key_tfm_list ; 
 int /*<<< orphan*/  key_tfm_list_mutex ; 
 int /*<<< orphan*/  mutex_init (int /*<<< orphan*/ *) ; 

int ecryptfs_init_crypto(void)
{
	mutex_init(&key_tfm_list_mutex);
	INIT_LIST_HEAD(&key_tfm_list);
	return 0;
}