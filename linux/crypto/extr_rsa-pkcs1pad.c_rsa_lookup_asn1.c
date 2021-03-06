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
struct rsa_asn1_template {scalar_t__ name; } ;

/* Variables and functions */
 struct rsa_asn1_template* rsa_asn1_templates ; 
 scalar_t__ strcmp (char const*,scalar_t__) ; 

__attribute__((used)) static const struct rsa_asn1_template *rsa_lookup_asn1(const char *name)
{
	const struct rsa_asn1_template *p;

	for (p = rsa_asn1_templates; p->name; p++)
		if (strcmp(name, p->name) == 0)
			return p;
	return NULL;
}