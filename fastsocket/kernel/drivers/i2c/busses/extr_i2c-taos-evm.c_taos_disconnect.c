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
struct taos_data {int /*<<< orphan*/  adapter; scalar_t__ client; } ;
struct serio {int /*<<< orphan*/  dev; } ;

/* Variables and functions */
 int /*<<< orphan*/  dev_dbg (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  i2c_del_adapter (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  i2c_unregister_device (scalar_t__) ; 
 int /*<<< orphan*/  kfree (struct taos_data*) ; 
 int /*<<< orphan*/  serio_close (struct serio*) ; 
 struct taos_data* serio_get_drvdata (struct serio*) ; 
 int /*<<< orphan*/  serio_set_drvdata (struct serio*,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void taos_disconnect(struct serio *serio)
{
	struct taos_data *taos = serio_get_drvdata(serio);

	if (taos->client)
		i2c_unregister_device(taos->client);
	i2c_del_adapter(&taos->adapter);
	serio_close(serio);
	serio_set_drvdata(serio, NULL);
	kfree(taos);

	dev_dbg(&serio->dev, "Disconnected from TAOS EVM\n");
}