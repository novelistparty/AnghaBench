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
struct adf_accel_dev {int dummy; } ;

/* Variables and functions */
 int EFAULT ; 
 scalar_t__ qat_crypto_create_instances (struct adf_accel_dev*) ; 

__attribute__((used)) static int qat_crypto_init(struct adf_accel_dev *accel_dev)
{
	if (qat_crypto_create_instances(accel_dev))
		return -EFAULT;

	return 0;
}