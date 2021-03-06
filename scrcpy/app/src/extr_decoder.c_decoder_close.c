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
struct decoder {int /*<<< orphan*/  codec_ctx; } ;

/* Variables and functions */
 int /*<<< orphan*/  avcodec_close (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  avcodec_free_context (int /*<<< orphan*/ *) ; 

void
decoder_close(struct decoder *decoder) {
    avcodec_close(decoder->codec_ctx);
    avcodec_free_context(&decoder->codec_ctx);
}