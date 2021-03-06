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
typedef  scalar_t__ PFNGLGETQUERYOBJECTUI64VEXTPROC ;
typedef  scalar_t__ PFNGLGETQUERYOBJECTI64VEXTPROC ;
typedef  scalar_t__ (* GLADloadproc ) (char*) ;

/* Variables and functions */
 int /*<<< orphan*/  GLAD_GL_EXT_timer_query ; 
 scalar_t__ glad_glGetQueryObjecti64vEXT ; 
 scalar_t__ glad_glGetQueryObjectui64vEXT ; 

__attribute__((used)) static void load_GL_EXT_timer_query(GLADloadproc load) {
	if(!GLAD_GL_EXT_timer_query) return;
	glad_glGetQueryObjecti64vEXT = (PFNGLGETQUERYOBJECTI64VEXTPROC)load("glGetQueryObjecti64vEXT");
	glad_glGetQueryObjectui64vEXT = (PFNGLGETQUERYOBJECTUI64VEXTPROC)load("glGetQueryObjectui64vEXT");
}