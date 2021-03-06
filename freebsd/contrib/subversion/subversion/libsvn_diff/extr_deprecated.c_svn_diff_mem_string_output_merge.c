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
typedef  int /*<<< orphan*/  svn_string_t ;
typedef  int /*<<< orphan*/  svn_stream_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  svn_diff_t ;
typedef  int /*<<< orphan*/  svn_diff_conflict_display_style_t ;
typedef  scalar_t__ svn_boolean_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  svn_diff_conflict_display_modified_latest ; 
 int /*<<< orphan*/  svn_diff_conflict_display_modified_original_latest ; 
 int /*<<< orphan*/  svn_diff_conflict_display_resolved_modified_latest ; 
 int /*<<< orphan*/ * svn_diff_mem_string_output_merge2 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,int /*<<< orphan*/  const*,char const*,char const*,char const*,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

svn_error_t *
svn_diff_mem_string_output_merge(svn_stream_t *output_stream,
                                 svn_diff_t *diff,
                                 const svn_string_t *original,
                                 const svn_string_t *modified,
                                 const svn_string_t *latest,
                                 const char *conflict_original,
                                 const char *conflict_modified,
                                 const char *conflict_latest,
                                 const char *conflict_separator,
                                 svn_boolean_t display_original_in_conflict,
                                 svn_boolean_t display_resolved_conflicts,
                                 apr_pool_t *pool)
{
  svn_diff_conflict_display_style_t style =
    svn_diff_conflict_display_modified_latest;

  if (display_resolved_conflicts)
    style = svn_diff_conflict_display_resolved_modified_latest;

  if (display_original_in_conflict)
    style = svn_diff_conflict_display_modified_original_latest;

  return svn_diff_mem_string_output_merge2(output_stream,
                                           diff,
                                           original,
                                           modified,
                                           latest,
                                           conflict_original,
                                           conflict_modified,
                                           conflict_latest,
                                           conflict_separator,
                                           style,
                                           pool);
}