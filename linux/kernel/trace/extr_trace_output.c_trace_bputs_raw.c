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
struct trace_seq {int dummy; } ;
struct trace_iterator {int /*<<< orphan*/  ent; struct trace_seq seq; } ;
struct trace_event {int dummy; } ;
struct bputs_entry {int /*<<< orphan*/  str; int /*<<< orphan*/  ip; } ;
typedef  enum print_line_t { ____Placeholder_print_line_t } print_line_t ;

/* Variables and functions */
 int /*<<< orphan*/  trace_assign_type (struct bputs_entry*,int /*<<< orphan*/ ) ; 
 int trace_handle_return (struct trace_seq*) ; 
 int /*<<< orphan*/  trace_seq_printf (struct trace_seq*,char*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  trace_seq_puts (struct trace_seq*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static enum print_line_t
trace_bputs_raw(struct trace_iterator *iter, int flags,
		struct trace_event *event)
{
	struct bputs_entry *field;
	struct trace_seq *s = &iter->seq;

	trace_assign_type(field, iter->ent);

	trace_seq_printf(s, ": %lx : ", field->ip);
	trace_seq_puts(s, field->str);

	return trace_handle_return(s);
}