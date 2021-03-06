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
struct ui_stream {int /*<<< orphan*/  stream; } ;

/* Variables and functions */
 int /*<<< orphan*/  ui_file_delete (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  xfree (struct ui_stream*) ; 

void
ui_out_stream_delete (struct ui_stream *buf)
{
  ui_file_delete (buf->stream);
  xfree (buf);
}