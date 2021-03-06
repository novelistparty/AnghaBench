#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {scalar_t__ buf_pos; scalar_t__ buf_len; int /*<<< orphan*/  pb; } ;
typedef  TYPE_1__ FFTextReader ;

/* Variables and functions */
 scalar_t__ avio_feof (int /*<<< orphan*/ ) ; 

int ff_text_eof(FFTextReader *r)
{
    return r->buf_pos >= r->buf_len && avio_feof(r->pb);
}