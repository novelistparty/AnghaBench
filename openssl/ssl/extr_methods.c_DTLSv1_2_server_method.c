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
typedef  int /*<<< orphan*/  SSL_METHOD ;

/* Variables and functions */
 int /*<<< orphan*/  const* dtlsv1_2_server_method () ; 

const SSL_METHOD *DTLSv1_2_server_method(void)
{
    return dtlsv1_2_server_method();
}