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
typedef  int /*<<< orphan*/  X509_NAME_ENTRY ;
typedef  int /*<<< orphan*/  X509_NAME ;
typedef  int /*<<< orphan*/  ASN1_OBJECT ;

/* Variables and functions */
 int /*<<< orphan*/ * X509_NAME_ENTRY_create_by_OBJ (int /*<<< orphan*/ *,int /*<<< orphan*/  const*,int,unsigned char const*,int) ; 
 int /*<<< orphan*/  X509_NAME_ENTRY_free (int /*<<< orphan*/ *) ; 
 int X509_NAME_add_entry (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int,int) ; 

int X509_NAME_add_entry_by_OBJ(X509_NAME *name, const ASN1_OBJECT *obj, int type,
                               const unsigned char *bytes, int len, int loc,
                               int set)
{
    X509_NAME_ENTRY *ne;
    int ret;

    ne = X509_NAME_ENTRY_create_by_OBJ(NULL, obj, type, bytes, len);
    if (!ne)
        return 0;
    ret = X509_NAME_add_entry(name, ne, loc, set);
    X509_NAME_ENTRY_free(ne);
    return ret;
}