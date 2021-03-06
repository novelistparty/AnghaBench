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
typedef  int /*<<< orphan*/  ldns_rdf ;

/* Variables and functions */
 int /*<<< orphan*/  LDNS_RDF_TYPE_A ; 
 int /*<<< orphan*/  LDNS_RDF_TYPE_AAAA ; 
 int /*<<< orphan*/ * ldns_rdf_new_frm_str (int /*<<< orphan*/ ,char const*) ; 

__attribute__((used)) static ldns_rdf *
ldns_rdf_new_addr_frm_str(const char *str) {
    ldns_rdf *addr;

    if ((addr = ldns_rdf_new_frm_str(LDNS_RDF_TYPE_A, str)) == NULL)
        addr = ldns_rdf_new_frm_str(LDNS_RDF_TYPE_AAAA, str);
    return addr;
}