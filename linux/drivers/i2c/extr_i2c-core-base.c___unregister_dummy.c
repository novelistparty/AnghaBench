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
struct i2c_client {int dummy; } ;
struct device {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  i2c_unregister_device (struct i2c_client*) ; 
 struct i2c_client* i2c_verify_client (struct device*) ; 

__attribute__((used)) static int __unregister_dummy(struct device *dev, void *dummy)
{
	struct i2c_client *client = i2c_verify_client(dev);
	i2c_unregister_device(client);
	return 0;
}