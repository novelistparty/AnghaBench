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
typedef  int /*<<< orphan*/  WORD ;

/* Variables and functions */
 int /*<<< orphan*/  L ; 
 int /*<<< orphan*/  R ; 
 scalar_t__ odd (int) ; 

__attribute__((used)) static WORD EmbeddingDirection(int level)
{
    return odd(level) ? R : L;
}