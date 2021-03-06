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
struct TYPE_4__ {int /*<<< orphan*/ * encodeMethod; int /*<<< orphan*/  reqType; int /*<<< orphan*/  ipstr; int /*<<< orphan*/  fd; } ;
typedef  TYPE_1__ HttpContext ;

/* Variables and functions */
 int /*<<< orphan*/  HTTP_REQTYPE_HEARTBEAT ; 
 int /*<<< orphan*/  gcHeartBeatMethod ; 
 int /*<<< orphan*/  httpTrace (char*,TYPE_1__*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

bool gcProcessHeartbeatRequest(HttpContext* pContext) {
  httpTrace("context:%p, fd:%d, ip:%s, process grafana heartbeat msg", pContext, pContext->fd, pContext->ipstr);
  pContext->reqType = HTTP_REQTYPE_HEARTBEAT;
  pContext->encodeMethod = &gcHeartBeatMethod;
  return true;
}