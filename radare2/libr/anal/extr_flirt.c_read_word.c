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
typedef  int ut32 ;
typedef  int /*<<< orphan*/  RBuffer ;

/* Variables and functions */
 int read_short (int /*<<< orphan*/ *) ; 

__attribute__((used)) static ut32 read_word(RBuffer *b) {
	ut32 r = (read_short (b) << 16);
	r += read_short (b);
	return r;
}