#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_14__   TYPE_7__ ;
typedef  struct TYPE_13__   TYPE_6__ ;
typedef  struct TYPE_12__   TYPE_5__ ;
typedef  struct TYPE_11__   TYPE_4__ ;
typedef  struct TYPE_10__   TYPE_3__ ;
typedef  struct TYPE_9__   TYPE_2__ ;
typedef  struct TYPE_8__   TYPE_1__ ;

/* Type definitions */
struct TYPE_11__ {int temp; int hysteresis; } ;
struct TYPE_10__ {int temp; int hysteresis; } ;
struct TYPE_9__ {int temp; int hysteresis; } ;
struct TYPE_8__ {int temp; int hysteresis; } ;
struct TYPE_12__ {TYPE_4__ thrs_shutdown; TYPE_3__ thrs_critical; TYPE_2__ thrs_down_clock; TYPE_1__ thrs_fan_boost; } ;
struct nouveau_therm_priv {int mode; TYPE_5__ bios_sensor; TYPE_6__* fan; } ;
struct nouveau_therm {int dummy; } ;
typedef  enum nouveau_therm_attr_type { ____Placeholder_nouveau_therm_attr_type } nouveau_therm_attr_type ;
struct TYPE_14__ {int min_duty; int max_duty; } ;
struct TYPE_13__ {TYPE_7__ bios; } ;

/* Variables and functions */
 int EINVAL ; 
#define  NOUVEAU_THERM_ATTR_FAN_MAX_DUTY 138 
#define  NOUVEAU_THERM_ATTR_FAN_MIN_DUTY 137 
#define  NOUVEAU_THERM_ATTR_FAN_MODE 136 
#define  NOUVEAU_THERM_ATTR_THRS_CRITICAL 135 
#define  NOUVEAU_THERM_ATTR_THRS_CRITICAL_HYST 134 
#define  NOUVEAU_THERM_ATTR_THRS_DOWN_CLK 133 
#define  NOUVEAU_THERM_ATTR_THRS_DOWN_CLK_HYST 132 
#define  NOUVEAU_THERM_ATTR_THRS_FAN_BOOST 131 
#define  NOUVEAU_THERM_ATTR_THRS_FAN_BOOST_HYST 130 
#define  NOUVEAU_THERM_ATTR_THRS_SHUTDOWN 129 
#define  NOUVEAU_THERM_ATTR_THRS_SHUTDOWN_HYST 128 

int
nouveau_therm_attr_get(struct nouveau_therm *therm,
		       enum nouveau_therm_attr_type type)
{
	struct nouveau_therm_priv *priv = (void *)therm;

	switch (type) {
	case NOUVEAU_THERM_ATTR_FAN_MIN_DUTY:
		return priv->fan->bios.min_duty;
	case NOUVEAU_THERM_ATTR_FAN_MAX_DUTY:
		return priv->fan->bios.max_duty;
	case NOUVEAU_THERM_ATTR_FAN_MODE:
		return priv->mode;
	case NOUVEAU_THERM_ATTR_THRS_FAN_BOOST:
		return priv->bios_sensor.thrs_fan_boost.temp;
	case NOUVEAU_THERM_ATTR_THRS_FAN_BOOST_HYST:
		return priv->bios_sensor.thrs_fan_boost.hysteresis;
	case NOUVEAU_THERM_ATTR_THRS_DOWN_CLK:
		return priv->bios_sensor.thrs_down_clock.temp;
	case NOUVEAU_THERM_ATTR_THRS_DOWN_CLK_HYST:
		return priv->bios_sensor.thrs_down_clock.hysteresis;
	case NOUVEAU_THERM_ATTR_THRS_CRITICAL:
		return priv->bios_sensor.thrs_critical.temp;
	case NOUVEAU_THERM_ATTR_THRS_CRITICAL_HYST:
		return priv->bios_sensor.thrs_critical.hysteresis;
	case NOUVEAU_THERM_ATTR_THRS_SHUTDOWN:
		return priv->bios_sensor.thrs_shutdown.temp;
	case NOUVEAU_THERM_ATTR_THRS_SHUTDOWN_HYST:
		return priv->bios_sensor.thrs_shutdown.hysteresis;
	}

	return -EINVAL;
}