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
typedef  int /*<<< orphan*/  hb_test_fixture_func_t ;
typedef  int /*<<< orphan*/  gsize ;
typedef  int /*<<< orphan*/  gconstpointer ;

/* Variables and functions */
 int /*<<< orphan*/  g_free (char*) ; 
 char* g_strdup_printf (char*,char const*,char const*) ; 
 int /*<<< orphan*/  hb_test_add_vtable (char*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static inline void
hb_test_add_vtable_flavor (const char             *test_path,
			   const char             *flavor,
			   gsize                   data_size,
			   gconstpointer           test_data,
			   hb_test_fixture_func_t  data_setup,
			   hb_test_fixture_func_t  data_test,
			   hb_test_fixture_func_t  data_teardown)
{
  char *path = g_strdup_printf ("%s/%s", test_path, flavor);
  hb_test_add_vtable (path, data_size, test_data, data_setup, data_test, data_teardown);
  g_free (path);
}