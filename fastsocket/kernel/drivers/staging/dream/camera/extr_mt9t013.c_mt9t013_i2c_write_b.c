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
typedef  scalar_t__ int32_t ;
typedef  int /*<<< orphan*/  buf ;

/* Variables and functions */
 scalar_t__ EIO ; 
 int /*<<< orphan*/  memset (unsigned char*,int /*<<< orphan*/ ,int) ; 
 scalar_t__ mt9t013_i2c_txdata (unsigned short,unsigned char*,int) ; 
 int /*<<< orphan*/  pr_err (char*,unsigned short,unsigned short) ; 

__attribute__((used)) static int32_t mt9t013_i2c_write_b(unsigned short saddr,
	unsigned short waddr, unsigned short wdata)
{
	int32_t rc = -EIO;
	unsigned char buf[2];

	memset(buf, 0, sizeof(buf));
	buf[0] = waddr;
	buf[1] = wdata;
	rc = mt9t013_i2c_txdata(saddr, buf, 2);

	if (rc < 0)
		pr_err("i2c_write failed, addr = 0x%x, val = 0x%x!\n",
		waddr, wdata);

	return rc;
}