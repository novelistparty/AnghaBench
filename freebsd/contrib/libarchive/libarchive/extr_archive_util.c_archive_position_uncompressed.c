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
struct archive {int dummy; } ;
typedef  int /*<<< orphan*/  la_int64_t ;

/* Variables and functions */
 int /*<<< orphan*/  archive_filter_bytes (struct archive*,int /*<<< orphan*/ ) ; 

la_int64_t
archive_position_uncompressed(struct archive *a)
{
	return archive_filter_bytes(a, 0);
}