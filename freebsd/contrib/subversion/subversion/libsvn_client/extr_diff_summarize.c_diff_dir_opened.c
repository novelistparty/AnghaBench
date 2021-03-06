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
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  svn_diff_source_t ;
typedef  int /*<<< orphan*/  svn_boolean_t ;
struct svn_diff_tree_processor_t {int dummy; } ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/ * SVN_NO_ERROR ; 

__attribute__((used)) static svn_error_t *
diff_dir_opened(void **new_dir_baton,
                svn_boolean_t *skip,
                svn_boolean_t *skip_children,
                const char *relpath,
                const svn_diff_source_t *left_source,
                const svn_diff_source_t *right_source,
                const svn_diff_source_t *copyfrom_source,
                void *parent_dir_baton,
                const struct svn_diff_tree_processor_t *processor,
                apr_pool_t *result_pool,
                apr_pool_t *scratch_pool)
{
  /* struct summarize_baton_t *b = processor->baton; */

  /* ### Send here instead of from dir_added() ? */
  /*if (!left_source)
    {
      SVN_ERR(send_summary(b, relpath, svn_client_diff_summarize_kind_added,
                           FALSE, svn_node_dir, scratch_pool));
    }*/

  return SVN_NO_ERROR;
}