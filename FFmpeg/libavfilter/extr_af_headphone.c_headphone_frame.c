#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_25__   TYPE_6__ ;
typedef  struct TYPE_24__   TYPE_5__ ;
typedef  struct TYPE_23__   TYPE_4__ ;
typedef  struct TYPE_22__   TYPE_3__ ;
typedef  struct TYPE_21__   TYPE_2__ ;
typedef  struct TYPE_20__   TYPE_1__ ;

/* Type definitions */
struct TYPE_21__ {int* n_clippings; int /*<<< orphan*/  temp_afft; int /*<<< orphan*/  temp_fft; int /*<<< orphan*/  temp_src; int /*<<< orphan*/  ringbuffer; int /*<<< orphan*/  ir; int /*<<< orphan*/  delay; int /*<<< orphan*/  write; TYPE_4__* out; TYPE_4__* in; } ;
typedef  TYPE_2__ ThreadData ;
struct TYPE_25__ {TYPE_1__* internal; } ;
struct TYPE_24__ {TYPE_6__* src; } ;
struct TYPE_23__ {int nb_samples; int /*<<< orphan*/  pts; } ;
struct TYPE_22__ {scalar_t__ type; int /*<<< orphan*/  temp_afft; int /*<<< orphan*/  temp_fft; int /*<<< orphan*/  temp_src; int /*<<< orphan*/  ringbuffer; int /*<<< orphan*/  data_ir; int /*<<< orphan*/  delay; int /*<<< orphan*/  write; } ;
struct TYPE_20__ {int /*<<< orphan*/  (* execute ) (TYPE_6__*,int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ *,int) ;} ;
typedef  TYPE_3__ HeadphoneContext ;
typedef  TYPE_4__ AVFrame ;
typedef  TYPE_5__ AVFilterLink ;
typedef  TYPE_6__ AVFilterContext ;

/* Variables and functions */
 int AVERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  AV_LOG_WARNING ; 
 int /*<<< orphan*/  ENOMEM ; 
 scalar_t__ TIME_DOMAIN ; 
 int /*<<< orphan*/  av_frame_free (TYPE_4__**) ; 
 int /*<<< orphan*/  av_log (TYPE_6__*,int /*<<< orphan*/ ,char*,int,int) ; 
 int /*<<< orphan*/  emms_c () ; 
 int ff_filter_frame (TYPE_5__*,TYPE_4__*) ; 
 TYPE_4__* ff_get_audio_buffer (TYPE_5__*,int) ; 
 int /*<<< orphan*/  headphone_convolute ; 
 int /*<<< orphan*/  headphone_fast_convolute ; 
 int /*<<< orphan*/  stub1 (TYPE_6__*,int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  stub2 (TYPE_6__*,int /*<<< orphan*/ ,TYPE_2__*,int /*<<< orphan*/ *,int) ; 

__attribute__((used)) static int headphone_frame(HeadphoneContext *s, AVFrame *in, AVFilterLink *outlink)
{
    AVFilterContext *ctx = outlink->src;
    int n_clippings[2] = { 0 };
    ThreadData td;
    AVFrame *out;

    out = ff_get_audio_buffer(outlink, in->nb_samples);
    if (!out) {
        av_frame_free(&in);
        return AVERROR(ENOMEM);
    }
    out->pts = in->pts;

    td.in = in; td.out = out; td.write = s->write;
    td.delay = s->delay; td.ir = s->data_ir; td.n_clippings = n_clippings;
    td.ringbuffer = s->ringbuffer; td.temp_src = s->temp_src;
    td.temp_fft = s->temp_fft;
    td.temp_afft = s->temp_afft;

    if (s->type == TIME_DOMAIN) {
        ctx->internal->execute(ctx, headphone_convolute, &td, NULL, 2);
    } else {
        ctx->internal->execute(ctx, headphone_fast_convolute, &td, NULL, 2);
    }
    emms_c();

    if (n_clippings[0] + n_clippings[1] > 0) {
        av_log(ctx, AV_LOG_WARNING, "%d of %d samples clipped. Please reduce gain.\n",
               n_clippings[0] + n_clippings[1], out->nb_samples * 2);
    }

    av_frame_free(&in);
    return ff_filter_frame(outlink, out);
}