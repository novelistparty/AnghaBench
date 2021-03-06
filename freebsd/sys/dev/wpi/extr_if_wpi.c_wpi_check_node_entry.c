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
typedef  int uint8_t ;
struct wpi_softc {int nodesmsk; } ;

/* Variables and functions */
 int WPI_ID_UNDEFINED ; 

__attribute__((used)) static __inline int
wpi_check_node_entry(struct wpi_softc *sc, uint8_t id)
{
	if (id == WPI_ID_UNDEFINED)
		return 0;

	return (sc->nodesmsk >> id) & 1;
}