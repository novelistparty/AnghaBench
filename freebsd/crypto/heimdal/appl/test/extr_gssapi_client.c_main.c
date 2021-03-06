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
typedef  int /*<<< orphan*/  krb5_context ;

/* Variables and functions */
 int client_doit (char*,int,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int client_setup (int /*<<< orphan*/ *,int*,char**) ; 
 int /*<<< orphan*/  proto ; 
 int /*<<< orphan*/  service ; 

int
main(int argc, char **argv)
{
    krb5_context context; /* XXX */
    int port = client_setup(&context, &argc, argv);
    return client_doit (argv[argc], port, service, proto);
}