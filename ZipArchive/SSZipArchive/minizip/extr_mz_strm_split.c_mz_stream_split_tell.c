#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_2__ ;
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  base; } ;
struct TYPE_4__ {TYPE_1__ stream; int /*<<< orphan*/  number_disk; } ;
typedef  TYPE_2__ mz_stream_split ;
typedef  scalar_t__ int64_t ;
typedef  scalar_t__ int32_t ;

/* Variables and functions */
 scalar_t__ MZ_OK ; 
 scalar_t__ mz_stream_split_goto_disk (void*,int /*<<< orphan*/ ) ; 
 scalar_t__ mz_stream_tell (int /*<<< orphan*/ ) ; 

int64_t mz_stream_split_tell(void *stream)
{
    mz_stream_split *split = (mz_stream_split *)stream;
    int32_t err = MZ_OK;
    err = mz_stream_split_goto_disk(stream, split->number_disk);
    if (err != MZ_OK)
        return err;
    return mz_stream_tell(split->stream.base);
}