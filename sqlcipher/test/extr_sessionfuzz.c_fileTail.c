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

__attribute__((used)) static const char *fileTail(const char *z){
  const char *zOut = z;
  while( z[0] ){
    if( z[0]=='/' && z[1]!=0 ) zOut = &z[1];
    z++;
  }
  return zOut;
}