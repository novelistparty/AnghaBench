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
typedef  int /*<<< orphan*/  sqlite3_value ;
typedef  int /*<<< orphan*/  sqlite3_context ;

/* Variables and functions */
 int /*<<< orphan*/  geo_debug ; 
 int /*<<< orphan*/  sqlite3_value_int (int /*<<< orphan*/ *) ; 

__attribute__((used)) static void geopolyDebugFunc(
  sqlite3_context *context,
  int argc,
  sqlite3_value **argv
){
#ifdef GEOPOLY_ENABLE_DEBUG
  geo_debug = sqlite3_value_int(argv[0]);
#endif
}