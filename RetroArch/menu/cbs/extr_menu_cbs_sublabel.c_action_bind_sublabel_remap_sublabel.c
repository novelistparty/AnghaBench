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
typedef  int /*<<< orphan*/  file_list_t ;

/* Variables and functions */
 int /*<<< orphan*/  MENU_ENUM_LABEL_VALUE_NOT_AVAILABLE ; 
 int /*<<< orphan*/  MENU_ENUM_LABEL_VALUE_USER ; 
 unsigned int MENU_SETTINGS_INPUT_DESC_BEGIN ; 
 int RARCH_FIRST_CUSTOM_BIND ; 
 char* input_config_get_device_display_name (unsigned int) ; 
 char* input_config_get_device_name (unsigned int) ; 
 char* msg_hash_to_str (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  snprintf (char*,size_t,char*,char*,unsigned int,char*) ; 

__attribute__((used)) static int action_bind_sublabel_remap_sublabel(
      file_list_t *list,
      unsigned type, unsigned i,
      const char *label, const char *path,
      char *s, size_t len)
{
   unsigned offset = (type - MENU_SETTINGS_INPUT_DESC_BEGIN)
      / (RARCH_FIRST_CUSTOM_BIND + 8);

   snprintf(s, len, "%s #%d: %s",
         msg_hash_to_str(MENU_ENUM_LABEL_VALUE_USER),
         offset + 1,
         input_config_get_device_display_name(offset) ?
         input_config_get_device_display_name(offset) :
         (input_config_get_device_name(offset) ?
          input_config_get_device_name(offset) :
          msg_hash_to_str(MENU_ENUM_LABEL_VALUE_NOT_AVAILABLE)));
   return 0;
}