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
typedef  int uint16_t ;
struct ena_admin_feature_rss_flow_hash_input {int enabled_input_sort; } ;

/* Variables and functions */
 int ENA_ADMIN_FEATURE_RSS_FLOW_HASH_INPUT_ENABLE_L4_SORT_MASK ; 
 int ENA_ADMIN_FEATURE_RSS_FLOW_HASH_INPUT_ENABLE_L4_SORT_SHIFT ; 

__attribute__((used)) static inline uint16_t get_ena_admin_feature_rss_flow_hash_input_enable_L4_sort(const struct ena_admin_feature_rss_flow_hash_input *p)
{
	return (p->enabled_input_sort & ENA_ADMIN_FEATURE_RSS_FLOW_HASH_INPUT_ENABLE_L4_SORT_MASK) >> ENA_ADMIN_FEATURE_RSS_FLOW_HASH_INPUT_ENABLE_L4_SORT_SHIFT;
}