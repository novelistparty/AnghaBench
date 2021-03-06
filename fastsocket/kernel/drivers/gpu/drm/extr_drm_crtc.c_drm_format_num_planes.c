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
typedef  int uint32_t ;

/* Variables and functions */
#define  DRM_FORMAT_NV12 143 
#define  DRM_FORMAT_NV16 142 
#define  DRM_FORMAT_NV21 141 
#define  DRM_FORMAT_NV24 140 
#define  DRM_FORMAT_NV42 139 
#define  DRM_FORMAT_NV61 138 
#define  DRM_FORMAT_YUV410 137 
#define  DRM_FORMAT_YUV411 136 
#define  DRM_FORMAT_YUV420 135 
#define  DRM_FORMAT_YUV422 134 
#define  DRM_FORMAT_YUV444 133 
#define  DRM_FORMAT_YVU410 132 
#define  DRM_FORMAT_YVU411 131 
#define  DRM_FORMAT_YVU420 130 
#define  DRM_FORMAT_YVU422 129 
#define  DRM_FORMAT_YVU444 128 

int drm_format_num_planes(uint32_t format)
{
	switch (format) {
	case DRM_FORMAT_YUV410:
	case DRM_FORMAT_YVU410:
	case DRM_FORMAT_YUV411:
	case DRM_FORMAT_YVU411:
	case DRM_FORMAT_YUV420:
	case DRM_FORMAT_YVU420:
	case DRM_FORMAT_YUV422:
	case DRM_FORMAT_YVU422:
	case DRM_FORMAT_YUV444:
	case DRM_FORMAT_YVU444:
		return 3;
	case DRM_FORMAT_NV12:
	case DRM_FORMAT_NV21:
	case DRM_FORMAT_NV16:
	case DRM_FORMAT_NV61:
	case DRM_FORMAT_NV24:
	case DRM_FORMAT_NV42:
		return 2;
	default:
		return 1;
	}
}