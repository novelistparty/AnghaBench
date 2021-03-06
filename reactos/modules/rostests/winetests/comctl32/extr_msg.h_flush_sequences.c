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
struct msg_sequence {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  flush_sequence (struct msg_sequence**,int) ; 

__attribute__((used)) static inline void flush_sequences(struct msg_sequence **seq, int n)
{
    int i;

    for (i = 0; i < n; i++)
        flush_sequence(seq, i);
}