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
struct rtmp_stream {int /*<<< orphan*/  active; } ;

/* Variables and functions */
 int os_atomic_load_bool (int /*<<< orphan*/ *) ; 

__attribute__((used)) static inline bool active(struct rtmp_stream *stream)
{
	return os_atomic_load_bool(&stream->active);
}