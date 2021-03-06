#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {char* data; } ;
typedef  TYPE_1__* StringInfo ;

/* Variables and functions */
 int /*<<< orphan*/  appendStringInfo (TYPE_1__*,char*,int /*<<< orphan*/ ) ; 
 TYPE_1__* makeStringInfo () ; 
 int /*<<< orphan*/  ts_number_of_user_hypertables () ; 

__attribute__((used)) static char *
get_num_hypertables()
{
	StringInfo buf = makeStringInfo();

	appendStringInfo(buf, "%d", ts_number_of_user_hypertables());
	return buf->data;
}