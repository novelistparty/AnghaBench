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
typedef  int /*<<< orphan*/  face_t ;

/* Variables and functions */
 int /*<<< orphan*/ * GetMemory (int) ; 
 int /*<<< orphan*/  c_faces ; 
 int /*<<< orphan*/  memset (int /*<<< orphan*/ *,int /*<<< orphan*/ ,int) ; 

face_t	*AllocFace (void)
{
	face_t	*f;

	f = GetMemory(sizeof(*f));
	memset (f, 0, sizeof(*f));
	c_faces++;

	return f;
}