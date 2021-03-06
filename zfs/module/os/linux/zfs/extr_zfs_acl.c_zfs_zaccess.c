#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_6__ ;
typedef  struct TYPE_11__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int z_pflags; int /*<<< orphan*/  z_xattr_parent; } ;
typedef  TYPE_1__ znode_t ;
typedef  int uint32_t ;
typedef  scalar_t__ uid_t ;
typedef  int mode_t ;
typedef  int /*<<< orphan*/  cred_t ;
typedef  scalar_t__ boolean_t ;
struct TYPE_12__ {int /*<<< orphan*/  i_uid; int /*<<< orphan*/  i_mode; } ;

/* Variables and functions */
 int ACE_APPEND_DATA ; 
 int ACE_DELETE ; 
 int ACE_DELETE_CHILD ; 
 int ACE_EXECUTE ; 
 int ACE_READ_ACL ; 
 int ACE_READ_ATTRIBUTES ; 
 int ACE_READ_DATA ; 
 int ACE_READ_NAMED_ATTRS ; 
 int ACE_SYNCHRONIZE ; 
 int ACE_WRITE_ACL ; 
 int ACE_WRITE_ATTRIBUTES ; 
 int ACE_WRITE_DATA ; 
 int ACE_WRITE_NAMED_ATTRS ; 
 int ACE_WRITE_OWNER ; 
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  EACCES ; 
 int /*<<< orphan*/  KUID_TO_SUID (int /*<<< orphan*/ ) ; 
 int SET_ERROR (int /*<<< orphan*/ ) ; 
 int S_IRUSR ; 
 scalar_t__ S_ISDIR (int /*<<< orphan*/ ) ; 
 int S_IWUSR ; 
 int S_IXUSR ; 
 int V_APPEND ; 
 int ZFS_CHECKED_MASKS ; 
 int /*<<< orphan*/  ZFS_OWNER ; 
 int ZFS_XATTR ; 
 TYPE_6__* ZTOI (TYPE_1__*) ; 
 int /*<<< orphan*/  ZTOZSB (TYPE_1__*) ; 
 scalar_t__ crgetuid (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  iput (TYPE_6__*) ; 
 int secpolicy_vnode_access2 (int /*<<< orphan*/ *,TYPE_6__*,scalar_t__,int,int) ; 
 int secpolicy_vnode_chown (int /*<<< orphan*/ *,scalar_t__) ; 
 int secpolicy_vnode_remove (int /*<<< orphan*/ *) ; 
 int secpolicy_vnode_setdac (int /*<<< orphan*/ *,scalar_t__) ; 
 scalar_t__ zfs_fuid_map_id (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int zfs_zaccess_append (TYPE_1__*,int*,scalar_t__*,int /*<<< orphan*/ *) ; 
 int zfs_zaccess_common (TYPE_1__*,int,int*,scalar_t__*,scalar_t__,int /*<<< orphan*/ *) ; 
 int zfs_zget (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_1__**) ; 

int
zfs_zaccess(znode_t *zp, int mode, int flags, boolean_t skipaclchk, cred_t *cr)
{
	uint32_t	working_mode;
	int		error;
	int		is_attr;
	boolean_t 	check_privs;
	znode_t		*xzp;
	znode_t 	*check_zp = zp;
	mode_t		needed_bits;
	uid_t		owner;

	is_attr = ((zp->z_pflags & ZFS_XATTR) && S_ISDIR(ZTOI(zp)->i_mode));

	/*
	 * If attribute then validate against base file
	 */
	if (is_attr) {
		if ((error = zfs_zget(ZTOZSB(zp),
		    zp->z_xattr_parent, &xzp)) != 0) {
			return (error);
		}

		check_zp = xzp;

		/*
		 * fixup mode to map to xattr perms
		 */

		if (mode & (ACE_WRITE_DATA|ACE_APPEND_DATA)) {
			mode &= ~(ACE_WRITE_DATA|ACE_APPEND_DATA);
			mode |= ACE_WRITE_NAMED_ATTRS;
		}

		if (mode & (ACE_READ_DATA|ACE_EXECUTE)) {
			mode &= ~(ACE_READ_DATA|ACE_EXECUTE);
			mode |= ACE_READ_NAMED_ATTRS;
		}
	}

	owner = zfs_fuid_map_id(ZTOZSB(zp), KUID_TO_SUID(ZTOI(zp)->i_uid),
	    cr, ZFS_OWNER);
	/*
	 * Map the bits required to the standard inode flags
	 * S_IRUSR|S_IWUSR|S_IXUSR in the needed_bits.  Map the bits
	 * mapped by working_mode (currently missing) in missing_bits.
	 * Call secpolicy_vnode_access2() with (needed_bits & ~checkmode),
	 * needed_bits.
	 */
	needed_bits = 0;

	working_mode = mode;
	if ((working_mode & (ACE_READ_ACL|ACE_READ_ATTRIBUTES)) &&
	    owner == crgetuid(cr))
		working_mode &= ~(ACE_READ_ACL|ACE_READ_ATTRIBUTES);

	if (working_mode & (ACE_READ_DATA|ACE_READ_NAMED_ATTRS|
	    ACE_READ_ACL|ACE_READ_ATTRIBUTES|ACE_SYNCHRONIZE))
		needed_bits |= S_IRUSR;
	if (working_mode & (ACE_WRITE_DATA|ACE_WRITE_NAMED_ATTRS|
	    ACE_APPEND_DATA|ACE_WRITE_ATTRIBUTES|ACE_SYNCHRONIZE))
		needed_bits |= S_IWUSR;
	if (working_mode & ACE_EXECUTE)
		needed_bits |= S_IXUSR;

	if ((error = zfs_zaccess_common(check_zp, mode, &working_mode,
	    &check_privs, skipaclchk, cr)) == 0) {
		if (is_attr)
			iput(ZTOI(xzp));
		return (secpolicy_vnode_access2(cr, ZTOI(zp), owner,
		    needed_bits, needed_bits));
	}

	if (error && !check_privs) {
		if (is_attr)
			iput(ZTOI(xzp));
		return (error);
	}

	if (error && (flags & V_APPEND)) {
		error = zfs_zaccess_append(zp, &working_mode, &check_privs, cr);
	}

	if (error && check_privs) {
		mode_t		checkmode = 0;

		/*
		 * First check for implicit owner permission on
		 * read_acl/read_attributes
		 */

		error = 0;
		ASSERT(working_mode != 0);

		if ((working_mode & (ACE_READ_ACL|ACE_READ_ATTRIBUTES) &&
		    owner == crgetuid(cr)))
			working_mode &= ~(ACE_READ_ACL|ACE_READ_ATTRIBUTES);

		if (working_mode & (ACE_READ_DATA|ACE_READ_NAMED_ATTRS|
		    ACE_READ_ACL|ACE_READ_ATTRIBUTES|ACE_SYNCHRONIZE))
			checkmode |= S_IRUSR;
		if (working_mode & (ACE_WRITE_DATA|ACE_WRITE_NAMED_ATTRS|
		    ACE_APPEND_DATA|ACE_WRITE_ATTRIBUTES|ACE_SYNCHRONIZE))
			checkmode |= S_IWUSR;
		if (working_mode & ACE_EXECUTE)
			checkmode |= S_IXUSR;

		error = secpolicy_vnode_access2(cr, ZTOI(check_zp), owner,
		    needed_bits & ~checkmode, needed_bits);

		if (error == 0 && (working_mode & ACE_WRITE_OWNER))
			error = secpolicy_vnode_chown(cr, owner);
		if (error == 0 && (working_mode & ACE_WRITE_ACL))
			error = secpolicy_vnode_setdac(cr, owner);

		if (error == 0 && (working_mode &
		    (ACE_DELETE|ACE_DELETE_CHILD)))
			error = secpolicy_vnode_remove(cr);

		if (error == 0 && (working_mode & ACE_SYNCHRONIZE)) {
			error = secpolicy_vnode_chown(cr, owner);
		}
		if (error == 0) {
			/*
			 * See if any bits other than those already checked
			 * for are still present.  If so then return EACCES
			 */
			if (working_mode & ~(ZFS_CHECKED_MASKS)) {
				error = SET_ERROR(EACCES);
			}
		}
	} else if (error == 0) {
		error = secpolicy_vnode_access2(cr, ZTOI(zp), owner,
		    needed_bits, needed_bits);
	}

	if (is_attr)
		iput(ZTOI(xzp));

	return (error);
}