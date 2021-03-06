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
typedef  int /*<<< orphan*/  yxml_t ;
typedef  int /*<<< orphan*/  yxml_ret_t ;

/* Variables and functions */
 int /*<<< orphan*/  YXML_OK ; 
 int /*<<< orphan*/  yxml_popstack (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline yxml_ret_t yxml_piabort  (yxml_t *x, unsigned ch) { yxml_popstack(x); return YXML_OK; }