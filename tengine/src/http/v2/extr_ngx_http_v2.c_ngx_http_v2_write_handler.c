#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_11__   TYPE_3__ ;
typedef  struct TYPE_10__   TYPE_2__ ;
typedef  struct TYPE_9__   TYPE_1__ ;

/* Type definitions */
typedef  scalar_t__ ngx_int_t ;
struct TYPE_9__ {int blocked; int /*<<< orphan*/ * last_out; } ;
typedef  TYPE_1__ ngx_http_v2_connection_t ;
struct TYPE_10__ {scalar_t__ timer_set; scalar_t__ timedout; TYPE_3__* data; } ;
typedef  TYPE_2__ ngx_event_t ;
struct TYPE_11__ {int error; int /*<<< orphan*/  buffered; int /*<<< orphan*/  log; TYPE_1__* data; } ;
typedef  TYPE_3__ ngx_connection_t ;

/* Variables and functions */
 scalar_t__ NGX_AGAIN ; 
 scalar_t__ NGX_ERROR ; 
 int /*<<< orphan*/  NGX_LOG_DEBUG_HTTP ; 
 int /*<<< orphan*/  ngx_del_timer (TYPE_2__*) ; 
 int /*<<< orphan*/  ngx_http_v2_finalize_connection (TYPE_1__*,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ngx_http_v2_handle_connection (TYPE_1__*) ; 
 scalar_t__ ngx_http_v2_send_output_queue (TYPE_1__*) ; 
 int /*<<< orphan*/  ngx_log_debug0 (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,char*) ; 

__attribute__((used)) static void
ngx_http_v2_write_handler(ngx_event_t *wev)
{
    ngx_int_t                  rc;
    ngx_connection_t          *c;
    ngx_http_v2_connection_t  *h2c;

    c = wev->data;
    h2c = c->data;

    if (wev->timedout) {
        ngx_log_debug0(NGX_LOG_DEBUG_HTTP, c->log, 0,
                       "http2 write event timed out");
        c->error = 1;
        ngx_http_v2_finalize_connection(h2c, 0);
        return;
    }

    ngx_log_debug0(NGX_LOG_DEBUG_HTTP, c->log, 0, "http2 write handler");

    if (h2c->last_out == NULL && !c->buffered) {

        if (wev->timer_set) {
            ngx_del_timer(wev);
        }

        ngx_http_v2_handle_connection(h2c);
        return;
    }

    h2c->blocked = 1;

    rc = ngx_http_v2_send_output_queue(h2c);

    if (rc == NGX_ERROR) {
        ngx_http_v2_finalize_connection(h2c, 0);
        return;
    }

    h2c->blocked = 0;

    if (rc == NGX_AGAIN) {
        return;
    }

    ngx_http_v2_handle_connection(h2c);
}