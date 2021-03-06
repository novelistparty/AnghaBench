#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
struct TYPE_10__ {TYPE_3__* wcroot; int /*<<< orphan*/  db; } ;
typedef  TYPE_1__ update_move_baton_t ;
typedef  int /*<<< orphan*/  svn_wc_conflict_reason_t ;
typedef  int /*<<< orphan*/  svn_sqlite__stmt_t ;
typedef  int /*<<< orphan*/  svn_skel_t ;
typedef  int /*<<< orphan*/  svn_node_kind_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  scalar_t__ svn_boolean_t ;
struct TYPE_11__ {scalar_t__ skip; TYPE_1__* umb; scalar_t__ shadowed; } ;
typedef  TYPE_2__ node_move_baton_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;
struct TYPE_12__ {int /*<<< orphan*/  wc_id; int /*<<< orphan*/  sdb; int /*<<< orphan*/  abspath; } ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/  STMT_INSERT_DELETE_FROM_NODE_RECURSIVE ; 
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 scalar_t__ TRUE ; 
 int /*<<< orphan*/  create_node_tree_conflict (int /*<<< orphan*/ **,TYPE_2__*,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mark_parent_edited (TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  mark_tc_on_op_root (TYPE_2__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  relpath_depth (char const*) ; 
 char* svn_dirent_join (int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_node_none ; 
 int /*<<< orphan*/  svn_sqlite__bindf (int /*<<< orphan*/ *,char*,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svn_sqlite__get_statement (int /*<<< orphan*/ **,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svn_sqlite__step_done (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_wc__db_op_make_copy_internal (TYPE_3__*,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_wc__db_wq_add_internal (TYPE_3__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_wc__node_has_local_mods (scalar_t__*,scalar_t__*,int /*<<< orphan*/ ,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_wc_conflict_action_delete ; 
 int /*<<< orphan*/  svn_wc_conflict_action_replace ; 
 int /*<<< orphan*/  svn_wc_conflict_reason_edited ; 
 int /*<<< orphan*/  svn_wc_notify_state_inapplicable ; 
 int /*<<< orphan*/  svn_wc_notify_update_delete ; 
 int /*<<< orphan*/  update_move_list_add (TYPE_3__*,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 

__attribute__((used)) static svn_error_t *
tc_incoming_editor_delete(node_move_baton_t *nmb,
                          const char *relpath,
                          svn_node_kind_t old_kind,
                          svn_node_kind_t new_kind,
                          apr_pool_t *scratch_pool)
{
  update_move_baton_t *b = nmb->umb;
  svn_sqlite__stmt_t *stmt;
  const char *local_abspath;
  svn_boolean_t is_modified, is_all_deletes;
  svn_skel_t *work_items = NULL;
  svn_skel_t *conflict = NULL;

  SVN_ERR(mark_parent_edited(nmb, scratch_pool));
  if (nmb->skip)
    return SVN_NO_ERROR;

  /* Check before retracting delete to catch delete-delete
     conflicts. This catches conflicts on the node itself; deleted
     children are caught as local modifications below.*/
  if (nmb->shadowed)
    {
      SVN_ERR(mark_tc_on_op_root(nmb,
                                 old_kind, new_kind,
                                 svn_wc_conflict_action_delete,
                                 scratch_pool));
      return SVN_NO_ERROR;
    }

  local_abspath = svn_dirent_join(b->wcroot->abspath, relpath, scratch_pool);
  SVN_ERR(svn_wc__node_has_local_mods(&is_modified, &is_all_deletes,
                                      nmb->umb->db, local_abspath, FALSE,
                                      NULL, NULL, scratch_pool));
  if (is_modified)
    {
      svn_wc_conflict_reason_t reason;

      /* No conflict means no NODES rows at the relpath op-depth
         so it's easy to convert the modified tree into a copy.

         Note the following assumptions for relpath:
            * it is not shadowed
            * it is not the/an op-root. (or we can't make us a copy)
       */

      SVN_ERR(svn_wc__db_op_make_copy_internal(b->wcroot, relpath, FALSE,
                                               NULL, NULL, scratch_pool));

      reason = svn_wc_conflict_reason_edited;

      SVN_ERR(create_node_tree_conflict(&conflict, nmb, relpath,
                                        old_kind, new_kind, reason,
                                        (new_kind == svn_node_none)
                                          ? svn_wc_conflict_action_delete
                                          : svn_wc_conflict_action_replace,
                                        NULL,
                                        scratch_pool, scratch_pool));
      nmb->skip = TRUE;
    }
  else
    {
      /* Delete the WORKING node at DST_RELPATH. */
      SVN_ERR(svn_sqlite__get_statement(&stmt, b->wcroot->sdb,
                                 STMT_INSERT_DELETE_FROM_NODE_RECURSIVE));
      SVN_ERR(svn_sqlite__bindf(stmt, "isdd",
                                b->wcroot->wc_id, relpath,
                                0, relpath_depth(relpath)));
      SVN_ERR(svn_sqlite__step_done(stmt));
    }

  /* Only notify if add_file/add_dir is not going to notify */
  if (conflict || (new_kind == svn_node_none))
    SVN_ERR(update_move_list_add(b->wcroot, relpath, b->db,
                                 svn_wc_notify_update_delete,
                                 new_kind,
                                 svn_wc_notify_state_inapplicable,
                                 svn_wc_notify_state_inapplicable,
                                 conflict, work_items, scratch_pool));
  else if (work_items)
    SVN_ERR(svn_wc__db_wq_add_internal(b->wcroot, work_items,
                                       scratch_pool));

  return SVN_NO_ERROR;
}