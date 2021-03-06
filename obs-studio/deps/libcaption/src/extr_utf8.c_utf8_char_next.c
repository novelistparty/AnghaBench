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
typedef  int /*<<< orphan*/  utf8_char_t ;

/* Variables and functions */
 int utf8_char_length (int /*<<< orphan*/  const*) ; 

const utf8_char_t* utf8_char_next(const utf8_char_t* c)
{
    const utf8_char_t* n = c + utf8_char_length(c);
    return n == c ? 0 : n;
}