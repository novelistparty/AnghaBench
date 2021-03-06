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
typedef  int /*<<< orphan*/  u32 ;
struct xdr_stream {int dummy; } ;
struct svc_rqst {int dummy; } ;
typedef  int /*<<< orphan*/  kgid_t ;
typedef  int /*<<< orphan*/  __be32 ;

/* Variables and functions */
 int /*<<< orphan*/  IDMAP_TYPE_GROUP ; 
 int /*<<< orphan*/  encode_name_from_id (struct xdr_stream*,struct svc_rqst*,int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  from_kgid_munged (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  nfsd_user_namespace (struct svc_rqst*) ; 

__be32 nfsd4_encode_group(struct xdr_stream *xdr, struct svc_rqst *rqstp,
			  kgid_t gid)
{
	u32 id = from_kgid_munged(nfsd_user_namespace(rqstp), gid);
	return encode_name_from_id(xdr, rqstp, IDMAP_TYPE_GROUP, id);
}