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
struct arcDisState {char const* (* condCodeName ) (int /*<<< orphan*/ ,int) ;int /*<<< orphan*/  _this; } ;

/* Variables and functions */
 char const* stub1 (int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static const char *
cond_code_name (struct arcDisState * state, int val)
{
	if (state->condCodeName) {
		return (*state->condCodeName) (state->_this, val);
	}
	return 0;
}