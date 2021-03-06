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
typedef  scalar_t__ uint64_t ;
typedef  int /*<<< orphan*/  u_longlong_t ;
typedef  int /*<<< orphan*/  snapname ;
typedef  int /*<<< orphan*/  boolean_t ;

/* Variables and functions */
 int /*<<< orphan*/  B_FALSE ; 
 int /*<<< orphan*/  B_TRUE ; 
 int EEXIST ; 
 int ENOSPC ; 
 int /*<<< orphan*/  FTAG ; 
 int ZFS_MAX_DATASET_NAME_LEN ; 
 int dmu_objset_snapshot_one (char*,char*) ; 
 int /*<<< orphan*/  fatal (int /*<<< orphan*/ ,char*,char*,char*,int) ; 
 int /*<<< orphan*/  snprintf (char*,int,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ztest_record_enospc (int /*<<< orphan*/ ) ; 

__attribute__((used)) static boolean_t
ztest_snapshot_create(char *osname, uint64_t id)
{
	char snapname[ZFS_MAX_DATASET_NAME_LEN];
	int error;

	(void) snprintf(snapname, sizeof (snapname), "%llu", (u_longlong_t)id);

	error = dmu_objset_snapshot_one(osname, snapname);
	if (error == ENOSPC) {
		ztest_record_enospc(FTAG);
		return (B_FALSE);
	}
	if (error != 0 && error != EEXIST) {
		fatal(0, "ztest_snapshot_create(%s@%s) = %d", osname,
		    snapname, error);
	}
	return (B_TRUE);
}