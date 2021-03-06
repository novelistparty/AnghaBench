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
typedef  int i64 ;
struct TYPE_3__ {int szSector; } ;
typedef  TYPE_1__ LogWriter ;

/* Variables and functions */

__attribute__((used)) static i64 firstByteOnSector(LogWriter *pLog, i64 iOff){
  return (iOff / pLog->szSector) * pLog->szSector;
}