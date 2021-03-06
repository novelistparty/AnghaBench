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
struct TYPE_4__ {scalar_t__ stream; scalar_t__ stream_end; int eof; int /*<<< orphan*/  f; } ;
typedef  TYPE_1__ vorb ;

/* Variables and functions */
 int /*<<< orphan*/  SEEK_SET ; 
 scalar_t__ USE_MEMORY (TYPE_1__*) ; 
 int /*<<< orphan*/  fseek (int /*<<< orphan*/ ,long,int /*<<< orphan*/ ) ; 
 long ftell (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void skip(vorb *z, int n)
{
   if (USE_MEMORY(z)) {
      z->stream += n;
      if (z->stream >= z->stream_end) z->eof = 1;
      return;
   }
   #ifndef STB_VORBIS_NO_STDIO
   {
      long x = ftell(z->f);
      fseek(z->f, x+n, SEEK_SET);
   }
   #endif
}