#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct eventhandler_lists_ctxt {int dummy; } ;
struct eventhandler_list {int dummy; } ;
struct eventhandler_entry_arg {int dummy; } ;
struct TYPE_2__ {int ee_priority; struct eventhandler_entry_arg ee_arg; } ;
struct eventhandler_entry_generic {TYPE_1__ ee; void* func; } ;
typedef  int /*<<< orphan*/  eventhandler_tag ;

/* Variables and functions */
 int /*<<< orphan*/  MCR_SLEEP ; 
 int /*<<< orphan*/  bzero (struct eventhandler_entry_generic*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  eg_cache ; 
 int /*<<< orphan*/  eg_size ; 
 int /*<<< orphan*/  eventhandler_register_internal (struct eventhandler_lists_ctxt*,struct eventhandler_list*,char const*,TYPE_1__*) ; 
 struct eventhandler_entry_generic* mcache_alloc (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

eventhandler_tag
eventhandler_register(struct eventhandler_lists_ctxt *evthdlr_lists_ctxt,
    struct eventhandler_list *list, const char *name,
    void *func, struct eventhandler_entry_arg arg, int priority)
{
	struct eventhandler_entry_generic	*eg;

	/* allocate an entry for this handler, populate it */
	eg = mcache_alloc(eg_cache, MCR_SLEEP);
	bzero(eg, eg_size);
	eg->func = func;
	eg->ee.ee_arg = arg;
	eg->ee.ee_priority = priority;

	return (eventhandler_register_internal(evthdlr_lists_ctxt, list, name, &eg->ee));
}