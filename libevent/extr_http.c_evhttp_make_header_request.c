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
struct evhttp_request {scalar_t__ type; int /*<<< orphan*/  output_headers; int /*<<< orphan*/  output_buffer; int /*<<< orphan*/  minor; int /*<<< orphan*/  major; int /*<<< orphan*/  uri; } ;
struct evhttp_connection {int /*<<< orphan*/  bufev; } ;
typedef  int /*<<< orphan*/  size ;
typedef  int ev_uint16_t ;

/* Variables and functions */
 int EVHTTP_METHOD_HAS_BODY ; 
 scalar_t__ EVHTTP_REQ_POST ; 
 scalar_t__ EVHTTP_REQ_PUT ; 
 int /*<<< orphan*/  EV_SIZE_ARG (scalar_t__) ; 
 int /*<<< orphan*/  EV_SIZE_FMT ; 
 int /*<<< orphan*/  bufferevent_get_output (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  evbuffer_add_printf (int /*<<< orphan*/ ,char*,char const*,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 scalar_t__ evbuffer_get_length (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  evhttp_add_header (int /*<<< orphan*/ ,char*,char*) ; 
 int /*<<< orphan*/ * evhttp_find_header (int /*<<< orphan*/ ,char*) ; 
 char* evhttp_method_ (struct evhttp_connection*,scalar_t__,int*) ; 
 int /*<<< orphan*/  evhttp_remove_header (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  evutil_snprintf (char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
evhttp_make_header_request(struct evhttp_connection *evcon,
    struct evhttp_request *req)
{
	const char *method;
	ev_uint16_t flags;

	evhttp_remove_header(req->output_headers, "Proxy-Connection");

	/* Generate request line */
	if (!(method = evhttp_method_(evcon, req->type, &flags))) {
		method = "NULL";
	}

	evbuffer_add_printf(bufferevent_get_output(evcon->bufev),
	    "%s %s HTTP/%d.%d\r\n",
	    method, req->uri, req->major, req->minor);

	/* Add the content length on a request if missing
	 * Always add it for POST and PUT requests as clients expect it */
	if ((flags & EVHTTP_METHOD_HAS_BODY) &&
	    (evbuffer_get_length(req->output_buffer) > 0 ||
	     req->type == EVHTTP_REQ_POST || req->type == EVHTTP_REQ_PUT) &&
	    evhttp_find_header(req->output_headers, "Content-Length") == NULL) {
		char size[22];
		evutil_snprintf(size, sizeof(size), EV_SIZE_FMT,
		    EV_SIZE_ARG(evbuffer_get_length(req->output_buffer)));
		evhttp_add_header(req->output_headers, "Content-Length", size);
	}
}