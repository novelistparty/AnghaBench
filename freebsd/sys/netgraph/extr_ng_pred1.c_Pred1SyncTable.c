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
typedef  int /*<<< orphan*/  u_char ;
typedef  TYPE_1__* priv_p ;
typedef  int /*<<< orphan*/  node_p ;
struct TYPE_3__ {size_t Hash; int /*<<< orphan*/ * GuessTable; } ;

/* Variables and functions */
 int /*<<< orphan*/  HASH (int /*<<< orphan*/ ) ; 
 TYPE_1__* NG_NODE_PRIVATE (int /*<<< orphan*/ ) ; 

__attribute__((used)) static void
Pred1SyncTable(node_p node, u_char *source, int len)
{
	const priv_p priv = NG_NODE_PRIVATE(node);

	while (len--) {
		priv->GuessTable[priv->Hash] = *source;
		HASH(*source++);
	}
}