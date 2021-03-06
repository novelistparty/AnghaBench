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
typedef  int /*<<< orphan*/  trail_t ;
typedef  int /*<<< orphan*/  svn_revnum_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  dag_node_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  svn_fs_base__dag_get_fs (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_fs_base__dag_get_id (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_fs_base__id_txn_id (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * svn_fs_base__txn_get_revision (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

svn_error_t *
svn_fs_base__dag_get_revision(svn_revnum_t *rev,
                              dag_node_t *node,
                              trail_t *trail,
                              apr_pool_t *pool)
{
  /* Use the txn ID from the NODE's id to look up the transaction and
     get its revision number.  */
  return svn_fs_base__txn_get_revision
    (rev, svn_fs_base__dag_get_fs(node),
     svn_fs_base__id_txn_id(svn_fs_base__dag_get_id(node)), trail, pool);
}