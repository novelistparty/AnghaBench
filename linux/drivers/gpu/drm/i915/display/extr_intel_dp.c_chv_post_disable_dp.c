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
struct TYPE_2__ {int /*<<< orphan*/  dev; } ;
struct intel_encoder {TYPE_1__ base; } ;
struct intel_crtc_state {int dummy; } ;
struct drm_i915_private {int dummy; } ;
struct drm_connector_state {int dummy; } ;

/* Variables and functions */
 int /*<<< orphan*/  chv_data_lane_soft_reset (struct intel_encoder*,struct intel_crtc_state const*,int) ; 
 int /*<<< orphan*/  intel_dp_link_down (struct intel_encoder*,struct intel_crtc_state const*) ; 
 struct drm_i915_private* to_i915 (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  vlv_dpio_get (struct drm_i915_private*) ; 
 int /*<<< orphan*/  vlv_dpio_put (struct drm_i915_private*) ; 

__attribute__((used)) static void chv_post_disable_dp(struct intel_encoder *encoder,
				const struct intel_crtc_state *old_crtc_state,
				const struct drm_connector_state *old_conn_state)
{
	struct drm_i915_private *dev_priv = to_i915(encoder->base.dev);

	intel_dp_link_down(encoder, old_crtc_state);

	vlv_dpio_get(dev_priv);

	/* Assert data lane reset */
	chv_data_lane_soft_reset(encoder, old_crtc_state, true);

	vlv_dpio_put(dev_priv);
}