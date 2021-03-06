#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct table {TYPE_1__* columns; } ;
typedef  size_t UINT ;
struct TYPE_2__ {int type; } ;

/* Variables and functions */
 int COL_TYPE_MASK ; 
 size_t get_type_size (int) ; 

__attribute__((used)) static UINT get_column_size( const struct table *table, UINT column )
{
    return get_type_size( table->columns[column].type & COL_TYPE_MASK );
}