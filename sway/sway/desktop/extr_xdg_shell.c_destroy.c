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
struct sway_xdg_shell_view {int dummy; } ;
struct sway_view {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  free (struct sway_xdg_shell_view*) ; 
 struct sway_xdg_shell_view* xdg_shell_view_from_view (struct sway_view*) ; 

__attribute__((used)) static void destroy(struct sway_view *view) {
	struct sway_xdg_shell_view *xdg_shell_view =
		xdg_shell_view_from_view(view);
	if (xdg_shell_view == NULL) {
		return;
	}
	free(xdg_shell_view);
}