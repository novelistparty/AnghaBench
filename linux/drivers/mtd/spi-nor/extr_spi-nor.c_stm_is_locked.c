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
typedef  int /*<<< orphan*/  uint64_t ;
struct spi_nor {int dummy; } ;
typedef  int /*<<< orphan*/  loff_t ;

/* Variables and functions */
 int read_sr (struct spi_nor*) ; 
 int stm_is_locked_sr (struct spi_nor*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int) ; 

__attribute__((used)) static int stm_is_locked(struct spi_nor *nor, loff_t ofs, uint64_t len)
{
	int status;

	status = read_sr(nor);
	if (status < 0)
		return status;

	return stm_is_locked_sr(nor, ofs, len, status);
}