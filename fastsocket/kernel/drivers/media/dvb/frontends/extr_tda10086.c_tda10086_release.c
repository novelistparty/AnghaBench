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
struct tda10086_state {int dummy; } ;
struct dvb_frontend {struct tda10086_state* demodulator_priv; } ;

/* Variables and functions */
 int /*<<< orphan*/  kfree (struct tda10086_state*) ; 
 int /*<<< orphan*/  tda10086_sleep (struct dvb_frontend*) ; 

__attribute__((used)) static void tda10086_release(struct dvb_frontend* fe)
{
	struct tda10086_state *state = fe->demodulator_priv;
	tda10086_sleep(fe);
	kfree(state);
}