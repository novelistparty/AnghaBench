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
struct nfs4_file {int dummy; } ;
struct nfs4_client {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static inline void nfsd4_return_all_file_layouts(struct nfs4_client *clp,
		struct nfs4_file *fp)
{
}