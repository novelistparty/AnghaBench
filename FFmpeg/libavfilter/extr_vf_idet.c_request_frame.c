#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_3__ ;
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {int /*<<< orphan*/ * inputs; TYPE_1__* priv; } ;
struct TYPE_6__ {TYPE_3__* src; } ;
struct TYPE_5__ {int eof; int /*<<< orphan*/  next; int /*<<< orphan*/  analyze_interlaced_flag_done; scalar_t__ cur; } ;
typedef  TYPE_1__ IDETContext ;
typedef  int /*<<< orphan*/  AVFrame ;
typedef  TYPE_2__ AVFilterLink ;
typedef  TYPE_3__ AVFilterContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int AVERROR_EOF ; 
 int /*<<< orphan*/  ENOMEM ; 
 int /*<<< orphan*/ * av_frame_clone (int /*<<< orphan*/ ) ; 
 int ff_request_frame (int /*<<< orphan*/ ) ; 
 int filter_frame (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static int request_frame(AVFilterLink *link)
{
    AVFilterContext *ctx = link->src;
    IDETContext *idet = ctx->priv;
    int ret;

    if (idet->eof)
        return AVERROR_EOF;

    ret = ff_request_frame(link->src->inputs[0]);

    if (ret == AVERROR_EOF && idet->cur && !idet->analyze_interlaced_flag_done) {
        AVFrame *next = av_frame_clone(idet->next);

        if (!next)
            return AVERROR(ENOMEM);

        ret = filter_frame(link->src->inputs[0], next);
        idet->eof = 1;
    }

    return ret;
}