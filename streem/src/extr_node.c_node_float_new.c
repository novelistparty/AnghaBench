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
struct TYPE_3__ {double value; int /*<<< orphan*/  type; } ;
typedef  TYPE_1__ node_float ;
typedef  int /*<<< orphan*/  node ;

/* Variables and functions */
 int /*<<< orphan*/  NODE_FLOAT ; 
 TYPE_1__* malloc (int) ; 

node*
node_float_new(double d)
{
  node_float* nf = malloc(sizeof(node_float));

  nf->type = NODE_FLOAT;
  nf->value = d;
  return (node*)nf;
}