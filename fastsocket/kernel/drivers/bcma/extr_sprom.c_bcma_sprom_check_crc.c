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
typedef  int u8 ;
typedef  int u16 ;

/* Variables and functions */
 int EPROTO ; 
 int SSB_SPROMSIZE_WORDS_R4 ; 
 int const SSB_SPROM_REVISION_CRC ; 
 int SSB_SPROM_REVISION_CRC_SHIFT ; 
 int bcma_sprom_crc (int const*) ; 

__attribute__((used)) static int bcma_sprom_check_crc(const u16 *sprom)
{
	u8 crc;
	u8 expected_crc;
	u16 tmp;

	crc = bcma_sprom_crc(sprom);
	tmp = sprom[SSB_SPROMSIZE_WORDS_R4 - 1] & SSB_SPROM_REVISION_CRC;
	expected_crc = tmp >> SSB_SPROM_REVISION_CRC_SHIFT;
	if (crc != expected_crc)
		return -EPROTO;

	return 0;
}