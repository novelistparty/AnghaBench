#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int uint16_t ;
struct TYPE_10__ {int flags; float opacity; int max; scalar_t__ display; int acomp; int ncomp; int pcomp; int const* grat_yuva_color; int nb_glines; int size; int /*<<< orphan*/  (* draw_text ) (TYPE_4__*,int,int,int const,float const,float const,char const*,int const*) ;scalar_t__ mirror; TYPE_2__* glines; int /*<<< orphan*/  (* blend_line ) (int /*<<< orphan*/ *,int const,int,float const,float const,int const,int const) ;scalar_t__ rgb; } ;
typedef  TYPE_3__ WaveformContext ;
struct TYPE_11__ {int height; int* linesize; scalar_t__* data; } ;
struct TYPE_9__ {TYPE_1__* line; } ;
struct TYPE_8__ {int pos; char* name; } ;
typedef  TYPE_4__ AVFrame ;

/* Variables and functions */
 scalar_t__ PARADE ; 
 scalar_t__ STACK ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ *,int const,int,float const,float const,int const,int const) ; 
 int /*<<< orphan*/  stub2 (TYPE_4__*,int,int,int const,float const,float const,char const*,int const*) ; 

__attribute__((used)) static void graticule16_row(WaveformContext *s, AVFrame *out)
{
    const int step = (s->flags & 2) + 1;
    const float o1 = s->opacity;
    const float o2 = 1. - o1;
    const int mult = s->max / 256;
    const int height = s->display == PARADE ? out->height / s->acomp : out->height;
    int C, k = 0, c, p, l, offset_x = 0, offset_y = 0;

    for (c = 0; c < s->ncomp; c++) {
        if (!((1 << c) & s->pcomp) || (!s->display && k > 0))
            continue;

        k++;
        C = s->rgb ? 0 : c;
        for (p = 0; p < s->ncomp; p++) {
            const int v = s->grat_yuva_color[p] * mult;
            for (l = 0; l < s->nb_glines ; l++) {
                const uint16_t pos = s->glines[l].line[C].pos;
                int x = offset_x + (s->mirror ? s->size - 1 - pos : pos);
                uint8_t *dst = (uint8_t *)(out->data[p] + offset_y * out->linesize[p]) + x * 2;

                s->blend_line(dst, height, out->linesize[p], o1, o2, v, step);
            }
        }

        for (l = 0; l < s->nb_glines && (s->flags & 1); l++) {
            const char *name = s->glines[l].line[C].name;
            const uint16_t pos = s->glines[l].line[C].pos;
            int x = offset_x + (s->mirror ? s->size - 1 - pos : pos) - 10;

            if (x < 0)
                x = 4;

            s->draw_text(out, x, offset_y + 2, mult, o1, o2, name, s->grat_yuva_color);
        }

        offset_x += s->size * (s->display == STACK);
        offset_y += height * (s->display == PARADE);
    }
}