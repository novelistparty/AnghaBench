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
typedef  int /*<<< orphan*/  svn_revnum_t ;
typedef  int /*<<< orphan*/  svn_opt_revision_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  svn_depth_t ;
typedef  int /*<<< orphan*/  svn_client_ctx_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;
typedef  int /*<<< orphan*/  apr_hash_t ;
typedef  int /*<<< orphan*/  apr_array_header_t ;

/* Variables and functions */
 int /*<<< orphan*/  svn_client_propget5 (int /*<<< orphan*/ **,int /*<<< orphan*/ *,char const*,char const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/  const*,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * svn_error_trace (int /*<<< orphan*/ ) ; 

svn_error_t *
svn_client_propget4(apr_hash_t **props,
                    const char *propname,
                    const char *target,
                    const svn_opt_revision_t *peg_revision,
                    const svn_opt_revision_t *revision,
                    svn_revnum_t *actual_revnum,
                    svn_depth_t depth,
                    const apr_array_header_t *changelists,
                    svn_client_ctx_t *ctx,
                    apr_pool_t *result_pool,
                    apr_pool_t *scratch_pool)
{
  return svn_error_trace(svn_client_propget5(props, NULL, propname, target,
                                             peg_revision, revision,
                                             actual_revnum, depth,
                                             changelists, ctx,
                                             result_pool, scratch_pool));
}