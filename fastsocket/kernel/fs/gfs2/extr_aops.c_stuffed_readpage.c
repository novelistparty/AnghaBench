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
typedef  int u64 ;
struct page {int /*<<< orphan*/  index; } ;
struct gfs2_inode {int /*<<< orphan*/  i_inode; } ;
struct gfs2_dinode {int dummy; } ;
struct buffer_head {int b_size; scalar_t__ b_data; } ;

/* Variables and functions */
 int /*<<< orphan*/  KM_USER0 ; 
 scalar_t__ PAGE_CACHE_SIZE ; 
 int /*<<< orphan*/  SetPageUptodate (struct page*) ; 
 int /*<<< orphan*/  brelse (struct buffer_head*) ; 
 int /*<<< orphan*/  flush_dcache_page (struct page*) ; 
 int gfs2_meta_inode_buffer (struct gfs2_inode*,struct buffer_head**) ; 
 int i_size_read (int /*<<< orphan*/ *) ; 
 void* kmap_atomic (struct page*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  kunmap_atomic (void*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  memcpy (void*,scalar_t__,int) ; 
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,scalar_t__) ; 
 scalar_t__ unlikely (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  zero_user (struct page*,int /*<<< orphan*/ ,scalar_t__) ; 

__attribute__((used)) static int stuffed_readpage(struct gfs2_inode *ip, struct page *page)
{
	struct buffer_head *dibh;
	u64 dsize = i_size_read(&ip->i_inode);
	void *kaddr;
	int error;

	/*
	 * Due to the order of unstuffing files and ->fault(), we can be
	 * asked for a zero page in the case of a stuffed file being extended,
	 * so we need to supply one here. It doesn't happen often.
	 */
	if (unlikely(page->index)) {
		zero_user(page, 0, PAGE_CACHE_SIZE);
		SetPageUptodate(page);
		return 0;
	}

	error = gfs2_meta_inode_buffer(ip, &dibh);
	if (error)
		return error;

	kaddr = kmap_atomic(page, KM_USER0);
	if (dsize > (dibh->b_size - sizeof(struct gfs2_dinode)))
		dsize = (dibh->b_size - sizeof(struct gfs2_dinode));
	memcpy(kaddr, dibh->b_data + sizeof(struct gfs2_dinode), dsize);
	memset(kaddr + dsize, 0, PAGE_CACHE_SIZE - dsize);
	kunmap_atomic(kaddr, KM_USER0);
	flush_dcache_page(page);
	brelse(dibh);
	SetPageUptodate(page);

	return 0;
}