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
typedef  int /*<<< orphan*/  uint32_t ;
struct bxe_softc {int dummy; } ;

/* Variables and functions */
 scalar_t__ CHIP_IS_E1 (struct bxe_softc*) ; 
 scalar_t__ DMAE_READY (struct bxe_softc*) ; 
 int /*<<< orphan*/  GUNZIP_BUF (struct bxe_softc*) ; 
 int /*<<< orphan*/  GUNZIP_PHYS (struct bxe_softc*) ; 
 int /*<<< orphan*/  ecore_init_ind_wr (struct bxe_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ecore_init_str_wr (struct bxe_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ecore_write_dmae_phys_len (struct bxe_softc*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void ecore_write_big_buf_wb(struct bxe_softc *sc, uint32_t addr, uint32_t len)
{
	if (DMAE_READY(sc))
		ecore_write_dmae_phys_len(sc, GUNZIP_PHYS(sc), addr, len);

	/* in E1 chips BIOS initiated ZLR may interrupt widebus writes */
	else if (CHIP_IS_E1(sc))
		ecore_init_ind_wr(sc, addr, GUNZIP_BUF(sc), len);

	/* in later chips PXP root complex handles BIOS ZLR w/o interrupting */
	else
		ecore_init_str_wr(sc, addr, GUNZIP_BUF(sc), len);
}