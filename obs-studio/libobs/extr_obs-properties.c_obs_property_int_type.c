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
struct int_data {int type; } ;
typedef  int /*<<< orphan*/  obs_property_t ;
typedef  enum obs_number_type { ____Placeholder_obs_number_type } obs_number_type ;

/* Variables and functions */
 int OBS_NUMBER_SCROLLER ; 
 int /*<<< orphan*/  OBS_PROPERTY_INT ; 
 struct int_data* get_type_data (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

enum obs_number_type obs_property_int_type(obs_property_t *p)
{
	struct int_data *data = get_type_data(p, OBS_PROPERTY_INT);
	return data ? data->type : OBS_NUMBER_SCROLLER;
}