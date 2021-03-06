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
typedef  int /*<<< orphan*/  wchar_t ;
typedef  int UINT ;

/* Variables and functions */
#define  PROXY_DIRECT 130 
#define  PROXY_HTTP 129 
#define  PROXY_SOCKS 128 
 int /*<<< orphan*/ * _UU (char*) ; 

wchar_t *GetProxyTypeStr(UINT i)
{
	switch (i)
	{
	case PROXY_DIRECT:

		return _UU("PROTO_DIRECT_TCP");

	case PROXY_HTTP:
		return _UU("PROTO_HTTP_PROXY");

	case PROXY_SOCKS:
		return _UU("PROTO_SOCKS_PROXY");

	default:
		return _UU("PROTO_UNKNOWN");
	}
}