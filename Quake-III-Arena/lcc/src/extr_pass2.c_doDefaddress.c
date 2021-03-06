#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_9__   TYPE_5__ ;
typedef  struct TYPE_8__   TYPE_3__ ;
typedef  struct TYPE_7__   TYPE_2__ ;
typedef  struct TYPE_6__   TYPE_1__ ;

/* Type definitions */
typedef  TYPE_3__* rcc_interface_ty ;
struct TYPE_9__ {int /*<<< orphan*/  (* defaddress ) (int /*<<< orphan*/ ) ;} ;
struct TYPE_6__ {int /*<<< orphan*/  p; } ;
struct TYPE_7__ {TYPE_1__ rcc_Defaddress; } ;
struct TYPE_8__ {TYPE_2__ v; } ;

/* Variables and functions */
 TYPE_5__* IR ; 
 int /*<<< orphan*/  stub1 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  uid2symbol (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void doDefaddress(rcc_interface_ty in) {
	(*IR->defaddress)(uid2symbol(in->v.rcc_Defaddress.p));
}