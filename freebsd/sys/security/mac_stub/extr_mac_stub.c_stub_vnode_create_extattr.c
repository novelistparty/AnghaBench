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
struct vnode {int dummy; } ;
struct ucred {int dummy; } ;
struct mount {int dummy; } ;
struct label {int dummy; } ;
struct componentname {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static int
stub_vnode_create_extattr(struct ucred *cred, struct mount *mp,
    struct label *mntlabel, struct vnode *dvp, struct label *dvplabel,
    struct vnode *vp, struct label *vplabel, struct componentname *cnp)
{

	return (0);
}