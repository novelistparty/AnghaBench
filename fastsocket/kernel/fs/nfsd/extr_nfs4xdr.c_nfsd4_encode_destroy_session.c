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
struct nfsd4_destroy_session {int dummy; } ;
struct nfsd4_compoundres {int dummy; } ;
typedef  int __be32 ;

/* Variables and functions */

__attribute__((used)) static __be32
nfsd4_encode_destroy_session(struct nfsd4_compoundres *resp, int nfserr,
			     struct nfsd4_destroy_session *destroy_session)
{
	return nfserr;
}