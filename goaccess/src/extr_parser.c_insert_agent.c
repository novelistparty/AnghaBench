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
typedef  int /*<<< orphan*/  GModule ;

/* Variables and functions */
 int /*<<< orphan*/  ht_insert_agent (int /*<<< orphan*/ ,int,int) ; 

__attribute__((used)) static void
insert_agent (int data_nkey, int agent_nkey, GModule module)
{
  ht_insert_agent (module, data_nkey, agent_nkey);
}