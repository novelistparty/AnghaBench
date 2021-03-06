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
struct vpx_image {size_t range; size_t cs; int fmt; int bit_depth; } ;
typedef  enum AVColorSpace { ____Placeholder_AVColorSpace } AVColorSpace ;
typedef  enum AVColorRange { ____Placeholder_AVColorRange } AVColorRange ;
struct TYPE_3__ {int color_range; int colorspace; scalar_t__ codec_id; int /*<<< orphan*/  pix_fmt; void* profile; } ;
typedef  TYPE_1__ AVCodecContext ;

/* Variables and functions */
#define  AVCOL_RANGE_JPEG 145 
#define  AVCOL_RANGE_MPEG 144 
#define  AVCOL_SPC_BT2020_NCL 143 
#define  AVCOL_SPC_BT470BG 142 
#define  AVCOL_SPC_BT709 141 
#define  AVCOL_SPC_RESERVED 140 
#define  AVCOL_SPC_RGB 139 
#define  AVCOL_SPC_SMPTE170M 138 
#define  AVCOL_SPC_SMPTE240M 137 
#define  AVCOL_SPC_UNSPECIFIED 136 
 int AVERROR_INVALIDDATA ; 
 scalar_t__ AV_CODEC_ID_VP8 ; 
 scalar_t__ AV_CODEC_ID_VP9 ; 
 int /*<<< orphan*/  AV_PIX_FMT_GBRP ; 
 int /*<<< orphan*/  AV_PIX_FMT_GBRP10 ; 
 int /*<<< orphan*/  AV_PIX_FMT_GBRP12 ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV420P ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV420P10 ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV420P12 ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV422P ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV422P10 ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV422P12 ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV440P ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV440P10 ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV440P12 ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV444P ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV444P10 ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUV444P12 ; 
 int /*<<< orphan*/  AV_PIX_FMT_YUVA420P ; 
 void* FF_PROFILE_VP9_0 ; 
 void* FF_PROFILE_VP9_1 ; 
 void* FF_PROFILE_VP9_2 ; 
 void* FF_PROFILE_VP9_3 ; 
#define  VPX_IMG_FMT_I420 135 
#define  VPX_IMG_FMT_I42016 134 
#define  VPX_IMG_FMT_I422 133 
#define  VPX_IMG_FMT_I42216 132 
#define  VPX_IMG_FMT_I440 131 
#define  VPX_IMG_FMT_I44016 130 
#define  VPX_IMG_FMT_I444 129 
#define  VPX_IMG_FMT_I44416 128 

__attribute__((used)) static int set_pix_fmt(AVCodecContext *avctx, struct vpx_image *img,
                       int has_alpha_channel)
{
    static const enum AVColorSpace colorspaces[8] = {
        AVCOL_SPC_UNSPECIFIED, AVCOL_SPC_BT470BG, AVCOL_SPC_BT709, AVCOL_SPC_SMPTE170M,
        AVCOL_SPC_SMPTE240M, AVCOL_SPC_BT2020_NCL, AVCOL_SPC_RESERVED, AVCOL_SPC_RGB,
    };
#if VPX_IMAGE_ABI_VERSION >= 4
    static const enum AVColorRange color_ranges[] = {
        AVCOL_RANGE_MPEG, AVCOL_RANGE_JPEG
    };
    avctx->color_range = color_ranges[img->range];
#endif
    avctx->colorspace = colorspaces[img->cs];
    if (avctx->codec_id == AV_CODEC_ID_VP8 && img->fmt != VPX_IMG_FMT_I420)
        return AVERROR_INVALIDDATA;
    switch (img->fmt) {
    case VPX_IMG_FMT_I420:
        if (avctx->codec_id == AV_CODEC_ID_VP9)
            avctx->profile = FF_PROFILE_VP9_0;
        avctx->pix_fmt =
            has_alpha_channel ? AV_PIX_FMT_YUVA420P : AV_PIX_FMT_YUV420P;
        return 0;
#if CONFIG_LIBVPX_VP9_DECODER
    case VPX_IMG_FMT_I422:
        avctx->profile = FF_PROFILE_VP9_1;
        avctx->pix_fmt = AV_PIX_FMT_YUV422P;
        return 0;
    case VPX_IMG_FMT_I440:
        avctx->profile = FF_PROFILE_VP9_1;
        avctx->pix_fmt = AV_PIX_FMT_YUV440P;
        return 0;
    case VPX_IMG_FMT_I444:
        avctx->profile = FF_PROFILE_VP9_1;
        avctx->pix_fmt = avctx->colorspace == AVCOL_SPC_RGB ?
                         AV_PIX_FMT_GBRP : AV_PIX_FMT_YUV444P;
        return 0;
    case VPX_IMG_FMT_I42016:
        avctx->profile = FF_PROFILE_VP9_2;
        if (img->bit_depth == 10) {
            avctx->pix_fmt = AV_PIX_FMT_YUV420P10;
            return 0;
        } else if (img->bit_depth == 12) {
            avctx->pix_fmt = AV_PIX_FMT_YUV420P12;
            return 0;
        } else {
            return AVERROR_INVALIDDATA;
        }
    case VPX_IMG_FMT_I42216:
        avctx->profile = FF_PROFILE_VP9_3;
        if (img->bit_depth == 10) {
            avctx->pix_fmt = AV_PIX_FMT_YUV422P10;
            return 0;
        } else if (img->bit_depth == 12) {
            avctx->pix_fmt = AV_PIX_FMT_YUV422P12;
            return 0;
        } else {
            return AVERROR_INVALIDDATA;
        }
    case VPX_IMG_FMT_I44016:
        avctx->profile = FF_PROFILE_VP9_3;
        if (img->bit_depth == 10) {
            avctx->pix_fmt = AV_PIX_FMT_YUV440P10;
            return 0;
        } else if (img->bit_depth == 12) {
            avctx->pix_fmt = AV_PIX_FMT_YUV440P12;
            return 0;
        } else {
            return AVERROR_INVALIDDATA;
        }
    case VPX_IMG_FMT_I44416:
        avctx->profile = FF_PROFILE_VP9_3;
        if (img->bit_depth == 10) {
            avctx->pix_fmt = avctx->colorspace == AVCOL_SPC_RGB ?
                             AV_PIX_FMT_GBRP10 : AV_PIX_FMT_YUV444P10;
            return 0;
        } else if (img->bit_depth == 12) {
            avctx->pix_fmt = avctx->colorspace == AVCOL_SPC_RGB ?
                             AV_PIX_FMT_GBRP12 : AV_PIX_FMT_YUV444P12;
            return 0;
        } else {
            return AVERROR_INVALIDDATA;
        }
#endif
    default:
        return AVERROR_INVALIDDATA;
    }
}