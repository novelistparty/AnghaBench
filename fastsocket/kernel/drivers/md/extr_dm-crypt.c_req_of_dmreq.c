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
struct dm_crypt_request {int dummy; } ;
struct crypt_config {int dmreq_start; } ;
struct ablkcipher_request {int dummy; } ;

/* Variables and functions */

__attribute__((used)) static struct ablkcipher_request *req_of_dmreq(struct crypt_config *cc,
					       struct dm_crypt_request *dmreq)
{
	return (struct ablkcipher_request *)((char *)dmreq - cc->dmreq_start);
}