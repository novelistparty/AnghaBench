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
struct bc_writer {int /*<<< orphan*/ * funcs; } ;

/* Variables and functions */
 int /*<<< orphan*/  TRACE (char*) ; 
 int /*<<< orphan*/  ps_2_x_backend ; 

__attribute__((used)) static void init_ps2x_dx9_writer(struct bc_writer *writer) {
    TRACE("Creating DirectX9 pixel shader 2.x writer\n");
    writer->funcs = &ps_2_x_backend;
}