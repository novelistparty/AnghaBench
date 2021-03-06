#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_2__   TYPE_1__ ;

/* Type definitions */
struct TYPE_2__ {scalar_t__ hi; scalar_t__ lo; } ;
union uint64_overlay {scalar_t__ full; TYPE_1__ part; } ;
typedef  scalar_t__ u64 ;
typedef  void* u32 ;
typedef  scalar_t__ s32 ;
typedef  int /*<<< orphan*/  acpi_status ;

/* Variables and functions */
 int /*<<< orphan*/  ACPI_DIV_64_BY_32 (void*,scalar_t__,scalar_t__,scalar_t__,void*) ; 
 int /*<<< orphan*/  ACPI_ERROR (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_FUNCTION_TRACE (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ACPI_SHIFT_RIGHT_64 (scalar_t__,void*) ; 
 int /*<<< orphan*/  AE_AML_DIVIDE_BY_ZERO ; 
 int /*<<< orphan*/  AE_INFO ; 
 int /*<<< orphan*/  AE_OK ; 
 int /*<<< orphan*/  return_ACPI_STATUS (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  ut_divide ; 

acpi_status
acpi_ut_divide(u64 in_dividend,
	       u64 in_divisor, u64 *out_quotient, u64 *out_remainder)
{
	union uint64_overlay dividend;
	union uint64_overlay divisor;
	union uint64_overlay quotient;
	union uint64_overlay remainder;
	union uint64_overlay normalized_dividend;
	union uint64_overlay normalized_divisor;
	u32 partial1;
	union uint64_overlay partial2;
	union uint64_overlay partial3;

	ACPI_FUNCTION_TRACE(ut_divide);

	/* Always check for a zero divisor */

	if (in_divisor == 0) {
		ACPI_ERROR((AE_INFO, "Divide by zero"));
		return_ACPI_STATUS(AE_AML_DIVIDE_BY_ZERO);
	}

	divisor.full = in_divisor;
	dividend.full = in_dividend;
	if (divisor.part.hi == 0) {
		/*
		 * 1) Simplest case is where the divisor is 32 bits, we can
		 * just do two divides
		 */
		remainder.part.hi = 0;

		/*
		 * The quotient is 64 bits, the remainder is always 32 bits,
		 * and is generated by the second divide.
		 */
		ACPI_DIV_64_BY_32(0, dividend.part.hi, divisor.part.lo,
				  quotient.part.hi, partial1);

		ACPI_DIV_64_BY_32(partial1, dividend.part.lo, divisor.part.lo,
				  quotient.part.lo, remainder.part.lo);
	}

	else {
		/*
		 * 2) The general case where the divisor is a full 64 bits
		 * is more difficult
		 */
		quotient.part.hi = 0;
		normalized_dividend = dividend;
		normalized_divisor = divisor;

		/* Normalize the operands (shift until the divisor is < 32 bits) */

		do {
			ACPI_SHIFT_RIGHT_64(normalized_divisor.part.hi,
					    normalized_divisor.part.lo);
			ACPI_SHIFT_RIGHT_64(normalized_dividend.part.hi,
					    normalized_dividend.part.lo);

		} while (normalized_divisor.part.hi != 0);

		/* Partial divide */

		ACPI_DIV_64_BY_32(normalized_dividend.part.hi,
				  normalized_dividend.part.lo,
				  normalized_divisor.part.lo, quotient.part.lo,
				  partial1);

		/*
		 * The quotient is always 32 bits, and simply requires
		 * adjustment. The 64-bit remainder must be generated.
		 */
		partial1 = quotient.part.lo * divisor.part.hi;
		partial2.full = (u64) quotient.part.lo * divisor.part.lo;
		partial3.full = (u64) partial2.part.hi + partial1;

		remainder.part.hi = partial3.part.lo;
		remainder.part.lo = partial2.part.lo;

		if (partial3.part.hi == 0) {
			if (partial3.part.lo >= dividend.part.hi) {
				if (partial3.part.lo == dividend.part.hi) {
					if (partial2.part.lo > dividend.part.lo) {
						quotient.part.lo--;
						remainder.full -= divisor.full;
					}
				} else {
					quotient.part.lo--;
					remainder.full -= divisor.full;
				}
			}

			remainder.full = remainder.full - dividend.full;
			remainder.part.hi = (u32)-((s32)remainder.part.hi);
			remainder.part.lo = (u32)-((s32)remainder.part.lo);

			if (remainder.part.lo) {
				remainder.part.hi--;
			}
		}
	}

	/* Return only what was requested */

	if (out_quotient) {
		*out_quotient = quotient.full;
	}
	if (out_remainder) {
		*out_remainder = remainder.full;
	}

	return_ACPI_STATUS(AE_OK);
}