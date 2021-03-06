#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {TYPE_2__* priv_data; } ;
typedef  TYPE_1__ URLContext ;
struct TYPE_5__ {int /*<<< orphan*/  stream; int /*<<< orphan*/  dh; } ;
typedef  TYPE_2__ RTMPEContext ;

/* Variables and functions */
 int /*<<< orphan*/  ff_dh_free (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ffurl_close (int /*<<< orphan*/ ) ; 

__attribute__((used)) static int rtmpe_close(URLContext *h)
{
    RTMPEContext *rt = h->priv_data;

    ff_dh_free(rt->dh);
    ffurl_close(rt->stream);

    return 0;
}