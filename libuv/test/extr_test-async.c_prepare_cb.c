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
typedef  int /*<<< orphan*/  uv_prepare_t ;

/* Variables and functions */
 int /*<<< orphan*/  ASSERT (int) ; 
 int /*<<< orphan*/  mutex ; 
 int /*<<< orphan*/  prepare ; 
 int /*<<< orphan*/  prepare_cb_called ; 
 int /*<<< orphan*/  thread ; 
 int /*<<< orphan*/  thread_cb ; 
 int /*<<< orphan*/  uv_mutex_unlock (int /*<<< orphan*/ *) ; 
 int uv_thread_create (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int /*<<< orphan*/ *) ; 

__attribute__((used)) static void prepare_cb(uv_prepare_t* handle) {
  int r;

  ASSERT(handle == &prepare);

  if (prepare_cb_called++)
    return;

  r = uv_thread_create(&thread, thread_cb, NULL);
  ASSERT(r == 0);
  uv_mutex_unlock(&mutex);
}