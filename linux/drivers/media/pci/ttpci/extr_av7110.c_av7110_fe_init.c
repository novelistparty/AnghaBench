#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct dvb_frontend {TYPE_1__* dvb; } ;
struct av7110 {int (* fe_init ) (struct dvb_frontend*) ;} ;
struct TYPE_2__ {struct av7110* priv; } ;

/* Variables and functions */
 int av7110_fe_lock_fix (struct av7110*,int /*<<< orphan*/ ) ; 
 int stub1 (struct dvb_frontend*) ; 

__attribute__((used)) static int av7110_fe_init(struct dvb_frontend* fe)
{
	struct av7110* av7110 = fe->dvb->priv;

	int ret = av7110_fe_lock_fix(av7110, 0);
	if (!ret)
		ret = av7110->fe_init(fe);
	return ret;
}