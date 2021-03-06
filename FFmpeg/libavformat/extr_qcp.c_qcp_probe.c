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
struct TYPE_3__ {char* buf; } ;
typedef  TYPE_1__ AVProbeData ;

/* Variables and functions */
 int AVPROBE_SCORE_MAX ; 
 scalar_t__ AV_RL32 (char*) ; 
 scalar_t__ AV_RL64 (char*) ; 

__attribute__((used)) static int qcp_probe(const AVProbeData *pd)
{
    if (AV_RL32(pd->buf  ) == AV_RL32("RIFF") &&
        AV_RL64(pd->buf+8) == AV_RL64("QLCMfmt "))
        return AVPROBE_SCORE_MAX;
    return 0;
}