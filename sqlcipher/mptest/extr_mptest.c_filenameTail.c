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

/* Variables and functions */
 scalar_t__ isDirSep (char) ; 

__attribute__((used)) static char *filenameTail(char *z){
  int i, j;
  for(i=j=0; z[i]; i++) if( isDirSep(z[i]) ) j = i+1;
  return z+j;
}