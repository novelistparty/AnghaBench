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
struct dvb_frontend {int dummy; } ;

/* Variables and functions */
 int DVBFE_ALGO_HW ; 
 int DVBFE_ALGO_SW ; 
 scalar_t__ dst_algo ; 

__attribute__((used)) static int dst_get_tuning_algo(struct dvb_frontend *fe)
{
	return dst_algo ? DVBFE_ALGO_HW : DVBFE_ALGO_SW;
}