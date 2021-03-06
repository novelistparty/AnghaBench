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
struct namespace {struct namespace* parent; int /*<<< orphan*/  name; } ;
typedef  int /*<<< orphan*/  FILE ;

/* Variables and functions */
 scalar_t__ is_global_namespace (struct namespace*) ; 
 scalar_t__ use_abi_namespace ; 
 int /*<<< orphan*/  write_line (int /*<<< orphan*/ *,int,char*,int /*<<< orphan*/ ) ; 

__attribute__((used)) static void write_namespace_end(FILE *header, struct namespace *namespace)
{
    if(is_global_namespace(namespace)) {
        if(use_abi_namespace)
            write_line(header, -1, "}", namespace->name);
        return;
    }

    write_line(header, -1, "}", namespace->name);
    write_namespace_end(header, namespace->parent);
}