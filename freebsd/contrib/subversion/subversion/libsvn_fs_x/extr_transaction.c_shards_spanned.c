#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_13__   TYPE_4__ ;
typedef  struct TYPE_12__   TYPE_3__ ;
typedef  struct TYPE_11__   TYPE_2__ ;
typedef  struct TYPE_10__   TYPE_1__ ;

/* Type definitions */
typedef  int svn_revnum_t ;
struct TYPE_11__ {int /*<<< orphan*/  change_set; } ;
struct TYPE_10__ {TYPE_2__ predecessor_id; scalar_t__ predecessor_count; } ;
typedef  TYPE_1__ svn_fs_x__noderev_t ;
typedef  TYPE_2__ svn_fs_x__id_t ;
struct TYPE_12__ {int max_files_per_dir; int youngest_rev_cache; } ;
typedef  TYPE_3__ svn_fs_x__data_t ;
struct TYPE_13__ {TYPE_3__* fsap_data; } ;
typedef  TYPE_4__ svn_fs_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 int /*<<< orphan*/  svn_fs_x__get_node_revision (TYPE_1__**,TYPE_4__*,TYPE_2__*,int /*<<< orphan*/ *,int /*<<< orphan*/ *) ; 
 int svn_fs_x__get_revnum (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svn_pool_clear (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * svn_pool_create (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_pool_destroy (int /*<<< orphan*/ *) ; 

__attribute__((used)) static svn_error_t *
shards_spanned(int *spanned,
               svn_fs_t *fs,
               svn_fs_x__noderev_t *noderev,
               int walk,
               apr_pool_t *scratch_pool)
{
  svn_fs_x__data_t *ffd = fs->fsap_data;
  int shard_size = ffd->max_files_per_dir;
  apr_pool_t *iterpool;

  int count = walk ? 1 : 0; /* The start of a walk already touches a shard. */
  svn_revnum_t shard, last_shard = ffd->youngest_rev_cache / shard_size;
  iterpool = svn_pool_create(scratch_pool);
  while (walk-- && noderev->predecessor_count)
    {
      svn_fs_x__id_t id = noderev->predecessor_id;

      svn_pool_clear(iterpool);
      SVN_ERR(svn_fs_x__get_node_revision(&noderev, fs, &id, scratch_pool,
                                          iterpool));
      shard = svn_fs_x__get_revnum(id.change_set) / shard_size;
      if (shard != last_shard)
        {
          ++count;
          last_shard = shard;
        }
    }
  svn_pool_destroy(iterpool);

  *spanned = count;
  return SVN_NO_ERROR;
}