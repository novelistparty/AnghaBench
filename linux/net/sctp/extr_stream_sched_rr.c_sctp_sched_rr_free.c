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
struct sctp_stream {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  sctp_sched_rr_unsched_all (struct sctp_stream*) ; 

__attribute__((used)) static void sctp_sched_rr_free(struct sctp_stream *stream)
{
	sctp_sched_rr_unsched_all(stream);
}