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
 int /*<<< orphan*/  abort () ; 
 int /*<<< orphan*/  fputs (char*,int /*<<< orphan*/ ) ; 
 void* realloc (void*,size_t) ; 
 int /*<<< orphan*/  stderr ; 

__attribute__((used)) static void* realloc_or_die(void* ptr, size_t n) {
  void* result = realloc(ptr, n);
  if (n > 0 && result == NULL) {
    fputs("Reallocation failure, aborting.\n", stderr);
    abort();
  }
  return result;
}