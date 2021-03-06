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
struct os_mbuf {int dummy; } ;
struct bt_mesh_msg_ctx {int dummy; } ;
struct bt_mesh_model {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  ESP_LOGI (int /*<<< orphan*/ ,char*) ; 
 int /*<<< orphan*/  gen_level_status (struct bt_mesh_model*,struct bt_mesh_msg_ctx*) ; 
 int /*<<< orphan*/  tag ; 

__attribute__((used)) static void gen_level_get(struct bt_mesh_model *model,
                          struct bt_mesh_msg_ctx *ctx,
                          struct os_mbuf *buf)
{
    ESP_LOGI(tag, "#mesh-level GET\n");

    gen_level_status(model, ctx);
}