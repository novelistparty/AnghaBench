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
struct _citrus_memory_stream {size_t ms_pos; } ;

/* Variables and functions */

__attribute__((used)) static __inline size_t
_citrus_memory_stream_tell(struct _citrus_memory_stream *ms)
{

	return (ms->ms_pos);
}