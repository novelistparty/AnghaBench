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
struct TYPE_4__ {char* command; char* help; TYPE_2__* argtable; int /*<<< orphan*/ * func; int /*<<< orphan*/ * hint; } ;
typedef  TYPE_1__ esp_console_cmd_t ;
struct TYPE_5__ {int /*<<< orphan*/  end; void* max_results; void* timeout; int /*<<< orphan*/  hostname; } ;

/* Variables and functions */
 int /*<<< orphan*/  ESP_ERROR_CHECK (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  arg_end (int) ; 
 void* arg_int0 (char*,char*,char*,char*) ; 
 int /*<<< orphan*/  arg_str1 (int /*<<< orphan*/ *,int /*<<< orphan*/ *,char*,char*) ; 
 int /*<<< orphan*/  cmd_mdns_query_ip ; 
 int /*<<< orphan*/  esp_console_cmd_register (TYPE_1__ const*) ; 
 TYPE_2__ mdns_query_ip_args ; 

__attribute__((used)) static void register_mdns_query_ip(void)
{
    mdns_query_ip_args.hostname = arg_str1(NULL, NULL, "<hostname>", "Hostname that is searched for");
    mdns_query_ip_args.timeout = arg_int0("t", "timeout", "<timeout>", "Timeout for this query");
    mdns_query_ip_args.max_results = arg_int0("m", "max_results", "<max_results>", "Maximum results returned");
    mdns_query_ip_args.end = arg_end(2);

    const esp_console_cmd_t cmd_init = {
        .command = "mdns_query_ip",
        .help = "Query MDNS for IP",
        .hint = NULL,
        .func = &cmd_mdns_query_ip,
        .argtable = &mdns_query_ip_args
    };

    ESP_ERROR_CHECK( esp_console_cmd_register(&cmd_init) );
}