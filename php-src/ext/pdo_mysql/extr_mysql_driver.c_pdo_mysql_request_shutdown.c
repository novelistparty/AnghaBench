#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_2__ ;
typedef  struct TYPE_5__   TYPE_1__ ;

/* Type definitions */
struct TYPE_5__ {scalar_t__ server; } ;
typedef  TYPE_1__ pdo_mysql_db_handle ;
struct TYPE_6__ {scalar_t__ driver_data; } ;
typedef  TYPE_2__ pdo_dbh_t ;

/* Variables and functions */
 int /*<<< orphan*/  PDO_DBG_ENTER (char*) ; 
 int /*<<< orphan*/  PDO_DBG_INF_FMT (char*,TYPE_2__*) ; 
 int /*<<< orphan*/  mysqlnd_end_psession (scalar_t__) ; 

__attribute__((used)) static void pdo_mysql_request_shutdown(pdo_dbh_t *dbh)
{
	pdo_mysql_db_handle *H = (pdo_mysql_db_handle *)dbh->driver_data;

	PDO_DBG_ENTER("pdo_mysql_request_shutdown");
	PDO_DBG_INF_FMT("dbh=%p", dbh);
#ifdef PDO_USE_MYSQLND
	if (H->server) {
		mysqlnd_end_psession(H->server);
	}
#endif
}