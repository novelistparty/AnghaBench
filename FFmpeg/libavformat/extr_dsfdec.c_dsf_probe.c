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
struct TYPE_3__ {int buf_size; scalar_t__ buf; } ;
typedef  TYPE_1__ AVProbeData ;

/* Variables and functions */
 int AVPROBE_SCORE_MAX ; 
 int AV_RL64 (scalar_t__) ; 
 scalar_t__ memcmp (scalar_t__,char*,int) ; 

__attribute__((used)) static int dsf_probe(const AVProbeData *p)
{
    if (p->buf_size < 12 || memcmp(p->buf, "DSD ", 4) || AV_RL64(p->buf + 4) != 28)
        return 0;
    return AVPROBE_SCORE_MAX;
}