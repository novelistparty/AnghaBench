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
typedef  int /*<<< orphan*/  decimal64 ;
typedef  int /*<<< orphan*/  decNumber ;

/* Variables and functions */
 int /*<<< orphan*/  decNumberToEngString (int /*<<< orphan*/ *,char*) ; 
 int /*<<< orphan*/  decimal64ToNumber (int /*<<< orphan*/  const*,int /*<<< orphan*/ *) ; 

char * decimal64ToEngString(const decimal64 *d64, char *string){
  decNumber dn;                         // work
  decimal64ToNumber(d64, &dn);
  decNumberToEngString(&dn, string);
  return string;
  }