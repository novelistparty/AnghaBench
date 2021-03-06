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
typedef  scalar_t__ PFNWGLFREEMEMORYNVPROC ;
typedef  scalar_t__ PFNWGLALLOCATEMEMORYNVPROC ;
typedef  scalar_t__ (* GLADloadproc ) (char*) ;

/* Variables and functions */
 int /*<<< orphan*/  GLAD_WGL_NV_vertex_array_range ; 
 scalar_t__ glad_wglAllocateMemoryNV ; 
 scalar_t__ glad_wglFreeMemoryNV ; 

__attribute__((used)) static void load_WGL_NV_vertex_array_range(GLADloadproc load) {
	if(!GLAD_WGL_NV_vertex_array_range) return;
	glad_wglAllocateMemoryNV = (PFNWGLALLOCATEMEMORYNVPROC)load("wglAllocateMemoryNV");
	glad_wglFreeMemoryNV = (PFNWGLFREEMEMORYNVPROC)load("wglFreeMemoryNV");
}