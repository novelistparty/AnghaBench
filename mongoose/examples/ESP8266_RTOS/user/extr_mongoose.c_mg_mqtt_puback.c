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
typedef  int /*<<< orphan*/  uint16_t ;
struct mg_connection {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  MG_MQTT_CMD_PUBACK ; 
 int /*<<< orphan*/  mg_send_mqtt_short_command (struct mg_connection*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

void mg_mqtt_puback(struct mg_connection *nc, uint16_t message_id) {
  mg_send_mqtt_short_command(nc, MG_MQTT_CMD_PUBACK, message_id);
}