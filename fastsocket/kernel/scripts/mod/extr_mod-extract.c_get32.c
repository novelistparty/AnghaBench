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
typedef  int /*<<< orphan*/  uint32_t ;
struct TYPE_2__ {int /*<<< orphan*/  (* get32 ) (int /*<<< orphan*/  const*) ;} ;

/* Variables and functions */
 TYPE_1__* order ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/  const*) ; 

__attribute__((used)) static inline uint32_t get32(const uint32_t *p) { return order->get32(p); }