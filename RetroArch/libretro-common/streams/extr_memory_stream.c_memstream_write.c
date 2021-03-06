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
typedef  scalar_t__ uint64_t ;
struct TYPE_4__ {scalar_t__ size; scalar_t__ ptr; scalar_t__ buf; } ;
typedef  TYPE_1__ memstream_t ;

/* Variables and functions */
 int /*<<< orphan*/  memcpy (scalar_t__,void const*,size_t) ; 
 int /*<<< orphan*/  memstream_update_pos (TYPE_1__*) ; 

uint64_t memstream_write(memstream_t *stream, const void *data, uint64_t bytes)
{
   uint64_t avail = 0;

   if (!stream)
      return 0;

   avail = stream->size - stream->ptr;
   if (bytes > avail)
      bytes = avail;

   memcpy(stream->buf + stream->ptr, data, (size_t)bytes);
   stream->ptr += bytes;
   memstream_update_pos(stream);
   return bytes;
}