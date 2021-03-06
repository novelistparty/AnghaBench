#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_7__ {TYPE_1__* priv_data; } ;
struct TYPE_6__ {int /*<<< orphan*/  qsv; } ;
typedef  TYPE_1__ QSVH2645Context ;
typedef  TYPE_2__ AVCodecContext ;

/* Variables and functions */
 int /*<<< orphan*/  ff_qsv_decode_flush (TYPE_2__*,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  qsv_clear_buffers (TYPE_1__*) ; 

__attribute__((used)) static void qsv_decode_flush(AVCodecContext *avctx)
{
    QSVH2645Context *s = avctx->priv_data;

    qsv_clear_buffers(s);
    ff_qsv_decode_flush(avctx, &s->qsv);
}