#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  svn_error_t ;
struct TYPE_2__ {int /*<<< orphan*/  conn; scalar_t__ got_status; } ;
typedef  TYPE_1__ ra_svn_edit_baton_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  svn_ra_svn__read_cmd_response (int /*<<< orphan*/ ,int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  svn_ra_svn__write_cmd_abort_edit (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static svn_error_t *ra_svn_abort_edit(void *edit_baton, apr_pool_t *pool)
{
  ra_svn_edit_baton_t *eb = edit_baton;

  if (eb->got_status)
    return SVN_NO_ERROR;
  SVN_ERR(svn_ra_svn__write_cmd_abort_edit(eb->conn, pool));
  SVN_ERR(svn_ra_svn__read_cmd_response(eb->conn, pool, ""));
  return SVN_NO_ERROR;
}