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
typedef  int /*<<< orphan*/  vec3_t ;
typedef  int /*<<< orphan*/  m4x4_t ;
typedef  int /*<<< orphan*/  eulerOrder_t ;

/* Variables and functions */
 int /*<<< orphan*/  m4x4_rotate_by_vec3 (int /*<<< orphan*/ ,int /*<<< orphan*/  const,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  m4x4_scale_by_vec3 (int /*<<< orphan*/ ,int /*<<< orphan*/  const) ; 
 int /*<<< orphan*/  m4x4_translate_by_vec3 (int /*<<< orphan*/ ,int /*<<< orphan*/  const) ; 

void m4x4_transform_by_vec3( m4x4_t matrix, const vec3_t translation, const vec3_t euler, eulerOrder_t order, const vec3_t scale ){
	m4x4_translate_by_vec3( matrix, translation );
	m4x4_rotate_by_vec3( matrix, euler, order );
	m4x4_scale_by_vec3( matrix, scale );
}