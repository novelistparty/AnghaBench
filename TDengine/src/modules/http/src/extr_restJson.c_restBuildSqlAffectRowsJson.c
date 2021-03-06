#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_3__   TYPE_1__ ;

/* Type definitions */
struct TYPE_3__ {int numOfRows; } ;
typedef  int /*<<< orphan*/  JsonBuf ;
typedef  TYPE_1__ HttpSqlCmd ;
typedef  int /*<<< orphan*/  HttpContext ;

/* Variables and functions */
 int /*<<< orphan*/  JsonArrEnd ; 
 int /*<<< orphan*/  JsonArrStt ; 
 int /*<<< orphan*/  httpJsonInt (int /*<<< orphan*/ *,int) ; 
 int /*<<< orphan*/  httpJsonItemToken (int /*<<< orphan*/ *) ; 
 int /*<<< orphan*/  httpJsonToken (int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/ * httpMallocJsonBuf (int /*<<< orphan*/ *) ; 

void restBuildSqlAffectRowsJson(HttpContext *pContext, HttpSqlCmd *cmd, int affect_rows) {
  JsonBuf *jsonBuf = httpMallocJsonBuf(pContext);
  if (jsonBuf == NULL) return;

  // data row array begin
  httpJsonItemToken(jsonBuf);
  httpJsonToken(jsonBuf, JsonArrStt);

  httpJsonItemToken(jsonBuf);
  httpJsonInt(jsonBuf, affect_rows);

  // data row array end
  httpJsonToken(jsonBuf, JsonArrEnd);

  cmd->numOfRows = affect_rows;
}