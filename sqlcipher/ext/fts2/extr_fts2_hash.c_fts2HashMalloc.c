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
 int /*<<< orphan*/  memset (void*,int /*<<< orphan*/ ,int) ; 
 void* sqlite3_malloc (int) ; 

__attribute__((used)) static void *fts2HashMalloc(int n){
  void *p = sqlite3_malloc(n);
  if( p ){
    memset(p, 0, n);
  }
  return p;
}