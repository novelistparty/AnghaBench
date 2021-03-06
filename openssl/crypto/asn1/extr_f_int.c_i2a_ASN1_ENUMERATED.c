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
typedef  int /*<<< orphan*/  BIO ;
typedef  int /*<<< orphan*/  ASN1_ENUMERATED ;

/* Variables and functions */
 int i2a_ASN1_INTEGER (int /*<<< orphan*/ *,int /*<<< orphan*/  const*) ; 

int i2a_ASN1_ENUMERATED(BIO *bp, const ASN1_ENUMERATED *a)
{
    return i2a_ASN1_INTEGER(bp, a);
}