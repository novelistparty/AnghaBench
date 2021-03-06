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
typedef  int /*<<< orphan*/  gchar ;
typedef  int /*<<< orphan*/  gboolean ;
typedef  int /*<<< orphan*/  GhbValue ;

/* Variables and functions */
 int /*<<< orphan*/  FALSE ; 
 int /*<<< orphan*/ * ghb_dict_get_value (int /*<<< orphan*/  const*,int /*<<< orphan*/  const*) ; 
 int /*<<< orphan*/  ghb_value_get_bool (int /*<<< orphan*/  const*) ; 

gboolean
ghb_dict_get_bool(const GhbValue *dict, const gchar *key)
{
    const GhbValue* value;
    value = ghb_dict_get_value(dict, key);
    if (value == NULL) return FALSE;
    return ghb_value_get_bool(value);
}