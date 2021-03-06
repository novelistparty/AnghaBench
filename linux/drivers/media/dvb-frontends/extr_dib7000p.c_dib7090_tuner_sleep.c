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
typedef  int u16 ;
struct dvb_frontend {struct dib7000p_state* demodulator_priv; } ;
struct dib7000p_state {int tuner_enable; } ;

/* Variables and functions */
 int dib7000p_read_word (struct dib7000p_state*,int) ; 
 int /*<<< orphan*/  dib7000p_write_word (struct dib7000p_state*,int,int) ; 
 int /*<<< orphan*/  dprintk (char*,int) ; 

__attribute__((used)) static int dib7090_tuner_sleep(struct dvb_frontend *fe, int onoff)
{
	struct dib7000p_state *state = fe->demodulator_priv;
	u16 en_cur_state;

	dprintk("sleep dib7090: %d\n", onoff);

	en_cur_state = dib7000p_read_word(state, 1922);

	if (en_cur_state > 0xff)
		state->tuner_enable = en_cur_state;

	if (onoff)
		en_cur_state &= 0x00ff;
	else {
		if (state->tuner_enable != 0)
			en_cur_state = state->tuner_enable;
	}

	dib7000p_write_word(state, 1922, en_cur_state);

	return 0;
}