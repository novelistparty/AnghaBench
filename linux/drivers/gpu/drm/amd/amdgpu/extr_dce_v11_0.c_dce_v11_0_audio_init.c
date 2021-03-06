#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_6__   TYPE_3__ ;
typedef  struct TYPE_5__   TYPE_2__ ;
typedef  struct TYPE_4__   TYPE_1__ ;

/* Type definitions */
struct TYPE_4__ {int enabled; int num_pins; TYPE_3__* pin; } ;
struct TYPE_5__ {TYPE_1__ audio; } ;
struct amdgpu_device {int asic_type; TYPE_2__ mode_info; } ;
struct TYPE_6__ {int channels; int rate; int bits_per_sample; int connected; int id; int /*<<< orphan*/  offset; scalar_t__ category_code; scalar_t__ status_bits; } ;

/* Variables and functions */
#define  CHIP_CARRIZO 133 
#define  CHIP_POLARIS10 132 
#define  CHIP_POLARIS11 131 
#define  CHIP_POLARIS12 130 
#define  CHIP_STONEY 129 
#define  CHIP_VEGAM 128 
 int EINVAL ; 
 int /*<<< orphan*/  amdgpu_audio ; 
 int /*<<< orphan*/  dce_v11_0_audio_enable (struct amdgpu_device*,TYPE_3__*,int) ; 
 int /*<<< orphan*/ * pin_offsets ; 

__attribute__((used)) static int dce_v11_0_audio_init(struct amdgpu_device *adev)
{
	int i;

	if (!amdgpu_audio)
		return 0;

	adev->mode_info.audio.enabled = true;

	switch (adev->asic_type) {
	case CHIP_CARRIZO:
	case CHIP_STONEY:
		adev->mode_info.audio.num_pins = 7;
		break;
	case CHIP_POLARIS10:
	case CHIP_VEGAM:
		adev->mode_info.audio.num_pins = 8;
		break;
	case CHIP_POLARIS11:
	case CHIP_POLARIS12:
		adev->mode_info.audio.num_pins = 6;
		break;
	default:
		return -EINVAL;
	}

	for (i = 0; i < adev->mode_info.audio.num_pins; i++) {
		adev->mode_info.audio.pin[i].channels = -1;
		adev->mode_info.audio.pin[i].rate = -1;
		adev->mode_info.audio.pin[i].bits_per_sample = -1;
		adev->mode_info.audio.pin[i].status_bits = 0;
		adev->mode_info.audio.pin[i].category_code = 0;
		adev->mode_info.audio.pin[i].connected = false;
		adev->mode_info.audio.pin[i].offset = pin_offsets[i];
		adev->mode_info.audio.pin[i].id = i;
		/* disable audio.  it will be set up later */
		/* XXX remove once we switch to ip funcs */
		dce_v11_0_audio_enable(adev, &adev->mode_info.audio.pin[i], false);
	}

	return 0;
}