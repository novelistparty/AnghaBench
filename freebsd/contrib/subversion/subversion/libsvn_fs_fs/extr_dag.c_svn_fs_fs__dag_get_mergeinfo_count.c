#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  svn_error_t ;
struct TYPE_3__ {int /*<<< orphan*/  mergeinfo_count; } ;
typedef  TYPE_1__ node_revision_t ;
typedef  int /*<<< orphan*/  dag_node_t ;
typedef  int /*<<< orphan*/  apr_int64_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  get_node_revision (TYPE_1__**,int /*<<< orphan*/ *) ; 

svn_error_t *
svn_fs_fs__dag_get_mergeinfo_count(apr_int64_t *count,
                                   dag_node_t *node)
{
  node_revision_t *noderev;

  SVN_ERR(get_node_revision(&noderev, node));
  *count = noderev->mergeinfo_count;
  return SVN_NO_ERROR;
}