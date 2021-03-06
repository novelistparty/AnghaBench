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
struct text_data {int type; } ;
struct obs_property {int dummy; } ;
typedef  struct obs_property obs_property_t ;
typedef  int /*<<< orphan*/  obs_properties_t ;
typedef  enum obs_text_type { ____Placeholder_obs_text_type } obs_text_type ;

/* Variables and functions */
 int /*<<< orphan*/  OBS_PROPERTY_TEXT ; 
 struct text_data* get_property_data (struct obs_property*) ; 
 scalar_t__ has_prop (int /*<<< orphan*/ *,char const*) ; 
 struct obs_property* new_prop (int /*<<< orphan*/ *,char const*,char const*,int /*<<< orphan*/ ) ; 

obs_property_t *obs_properties_add_text(obs_properties_t *props,
					const char *name, const char *desc,
					enum obs_text_type type)
{
	if (!props || has_prop(props, name))
		return NULL;

	struct obs_property *p = new_prop(props, name, desc, OBS_PROPERTY_TEXT);
	struct text_data *data = get_property_data(p);
	data->type = type;
	return p;
}