#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
struct TYPE_6__ {int /*<<< orphan*/  server; } ;
typedef  TYPE_1__ pdo_mysql_db_handle ;
struct TYPE_7__ {struct TYPE_7__* auto_commit; scalar_t__ driver_data; } ;
typedef  TYPE_2__ pdo_dbh_t ;

/* Variables and functions */
 int /*<<< orphan*/  PDO_DBG_ENTER (char*) ; 
 int /*<<< orphan*/  PDO_DBG_INF_FMT (char*,TYPE_2__*) ; 
 int /*<<< orphan*/  PDO_DBG_RETURN (int) ; 
 scalar_t__ mysql_autocommit (int /*<<< orphan*/ ,TYPE_2__*) ; 

__attribute__((used)) static inline int mysql_handle_autocommit(pdo_dbh_t *dbh)
{
	PDO_DBG_ENTER("mysql_handle_autocommit");
	PDO_DBG_INF_FMT("dbh=%p", dbh);
	PDO_DBG_INF_FMT("dbh->autocommit=%d", dbh->auto_commit);
	PDO_DBG_RETURN(0 <= mysql_autocommit(((pdo_mysql_db_handle *)dbh->driver_data)->server, dbh->auto_commit));
}