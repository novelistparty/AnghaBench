#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_16__   TYPE_5__ ;
typedef  struct TYPE_15__   TYPE_4__ ;
typedef  struct TYPE_14__   TYPE_3__ ;
typedef  struct TYPE_13__   TYPE_2__ ;
typedef  struct TYPE_12__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  svn_stream_t ;
struct TYPE_13__ {TYPE_5__* fsap_data; } ;
typedef  TYPE_2__ svn_fs_t ;
typedef  int /*<<< orphan*/  svn_error_t ;
typedef  scalar_t__ svn_boolean_t ;
struct TYPE_12__ {int /*<<< orphan*/  revision; } ;
struct rep_read_baton {TYPE_1__ fulltext_cache_key; scalar_t__ fulltext_cache; } ;
struct TYPE_14__ {int /*<<< orphan*/  expanded_size; int /*<<< orphan*/  revision; int /*<<< orphan*/  item_index; } ;
typedef  TYPE_3__ representation_t ;
struct TYPE_15__ {int /*<<< orphan*/  second; int /*<<< orphan*/  revision; int /*<<< orphan*/  member_0; } ;
typedef  TYPE_4__ pair_cache_key_t ;
struct TYPE_16__ {scalar_t__ fulltext_cache; } ;
typedef  TYPE_5__ fs_fs_data_t ;
typedef  int /*<<< orphan*/  apr_pool_t ;

/* Variables and functions */
 int /*<<< orphan*/  SVN_ERR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  SVN_INVALID_REVNUM ; 
 scalar_t__ SVN_IS_VALID_REVNUM (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * SVN_NO_ERROR ; 
 scalar_t__ fulltext_size_is_cachable (TYPE_5__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  rep_read_contents ; 
 int /*<<< orphan*/  rep_read_contents_close ; 
 int /*<<< orphan*/  rep_read_get_baton (struct rep_read_baton**,TYPE_2__*,TYPE_3__*,TYPE_4__,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * svn_stream_create (struct rep_read_baton*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/ * svn_stream_empty (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  svn_stream_set_close (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  svn_stream_set_read2 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

svn_error_t *
svn_fs_fs__get_contents(svn_stream_t **contents_p,
                        svn_fs_t *fs,
                        representation_t *rep,
                        svn_boolean_t cache_fulltext,
                        apr_pool_t *pool)
{
  if (! rep)
    {
      *contents_p = svn_stream_empty(pool);
    }
  else
    {
      fs_fs_data_t *ffd = fs->fsap_data;
      struct rep_read_baton *rb;

      pair_cache_key_t fulltext_cache_key = { 0 };
      fulltext_cache_key.revision = rep->revision;
      fulltext_cache_key.second = rep->item_index;

      /* Initialize the reader baton.  Some members may added lazily
       * while reading from the stream */
      SVN_ERR(rep_read_get_baton(&rb, fs, rep, fulltext_cache_key, pool));

      /* Make the stream attempt fulltext cache lookups if the fulltext
       * is cacheable.  If it is not, then also don't try to buffer and
       * cache it. */
      if (ffd->fulltext_cache && cache_fulltext
          && SVN_IS_VALID_REVNUM(rep->revision)
          && fulltext_size_is_cachable(ffd, rep->expanded_size))
        {
          rb->fulltext_cache = ffd->fulltext_cache;
        }
      else
        {
          /* This will also prevent the reconstructed fulltext from being
             put into the cache. */
          rb->fulltext_cache_key.revision = SVN_INVALID_REVNUM;
        }

      *contents_p = svn_stream_create(rb, pool);
      svn_stream_set_read2(*contents_p, NULL /* only full read support */,
                           rep_read_contents);
      svn_stream_set_close(*contents_p, rep_read_contents_close);
    }

  return SVN_NO_ERROR;
}