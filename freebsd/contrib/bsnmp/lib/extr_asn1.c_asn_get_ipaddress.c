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
typedef  int u_char ;
struct asn_buf {int dummy; } ;
typedef  enum asn_err { ____Placeholder_asn_err } asn_err ;
typedef  int /*<<< orphan*/  asn_len_t ;

/* Variables and functions */
 int ASN_APP_IPADDRESS ; 
 int ASN_CLASS_APPLICATION ; 
 int ASN_ERR_OK ; 
 int ASN_ERR_TAG ; 
 int /*<<< orphan*/  asn_error (struct asn_buf*,char*,int) ; 
 int asn_get_header (struct asn_buf*,int*,int /*<<< orphan*/ *) ; 
 int asn_get_ipaddress_raw (struct asn_buf*,int /*<<< orphan*/ ,int*) ; 

enum asn_err
asn_get_ipaddress(struct asn_buf *b, u_char *addr)
{
	u_char type;
	asn_len_t len;
	enum asn_err err;

	if ((err = asn_get_header(b, &type, &len)) != ASN_ERR_OK)
		return (err);
	if (type != (ASN_CLASS_APPLICATION|ASN_APP_IPADDRESS)) {
		asn_error(b, "bad type for ip-address %u", type);
		return (ASN_ERR_TAG);
	}
	return (asn_get_ipaddress_raw(b, len, addr));
}