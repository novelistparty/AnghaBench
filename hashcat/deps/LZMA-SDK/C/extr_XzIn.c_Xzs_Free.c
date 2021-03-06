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
struct TYPE_3__ {size_t num; size_t numAllocated; int /*<<< orphan*/ * streams; } ;
typedef  int /*<<< orphan*/  ISzAllocPtr ;
typedef  TYPE_1__ CXzs ;

/* Variables and functions */
 int /*<<< orphan*/  ISzAlloc_Free (int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  Xz_Free (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 

void Xzs_Free(CXzs *p, ISzAllocPtr alloc)
{
  size_t i;
  for (i = 0; i < p->num; i++)
    Xz_Free(&p->streams[i], alloc);
  ISzAlloc_Free(alloc, p->streams);
  p->num = p->numAllocated = 0;
  p->streams = 0;
}