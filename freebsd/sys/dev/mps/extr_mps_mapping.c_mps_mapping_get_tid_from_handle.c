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
typedef  int /*<<< orphan*/  u16 ;
struct mps_softc {int dummy; } ;

/* Variables and functions */
 unsigned int _mapping_get_mt_idx_from_handle (struct mps_softc*,int /*<<< orphan*/ ) ; 

unsigned int
mps_mapping_get_tid_from_handle(struct mps_softc *sc, u16 handle)
{
	return (_mapping_get_mt_idx_from_handle(sc, handle));
}