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
typedef  int /*<<< orphan*/  CMS_ContentInfo ;
typedef  int /*<<< orphan*/  BIO ;

/* Variables and functions */
 int /*<<< orphan*/  CMS_F_CMS_COMPRESS ; 
 int /*<<< orphan*/  CMS_R_UNSUPPORTED_COMPRESSION_ALGORITHM ; 
 int /*<<< orphan*/  CMSerr (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 

CMS_ContentInfo *CMS_compress(BIO *in, int comp_nid, unsigned int flags)
{
    CMSerr(CMS_F_CMS_COMPRESS, CMS_R_UNSUPPORTED_COMPRESSION_ALGORITHM);
    return NULL;
}