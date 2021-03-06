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
typedef  int /*<<< orphan*/  AlgorithmIdentifier ;

/* Variables and functions */
 int /*<<< orphan*/  const _hx509_signature_rsa_with_sha256_data ; 

const AlgorithmIdentifier *
hx509_signature_rsa_with_sha256(void)
{ return &_hx509_signature_rsa_with_sha256_data; }