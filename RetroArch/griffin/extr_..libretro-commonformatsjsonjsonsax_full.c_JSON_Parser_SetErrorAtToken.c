#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int /*<<< orphan*/  errorOffset; int /*<<< orphan*/  error; } ;
typedef  TYPE_1__* JSON_Parser ;
typedef  int /*<<< orphan*/  Error ;

/* Variables and functions */
 int /*<<< orphan*/  ERROR_LOCATION_IS_TOKEN_START ; 

__attribute__((used)) static void JSON_Parser_SetErrorAtToken(JSON_Parser parser, Error error)
{
   parser->error = error;
   parser->errorOffset = ERROR_LOCATION_IS_TOKEN_START;
}