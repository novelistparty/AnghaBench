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
typedef  int /*<<< orphan*/  UINT ;
typedef  int /*<<< orphan*/  BUF ;

/* Variables and functions */
 int /*<<< orphan*/  Endian32 (int /*<<< orphan*/ ) ; 
 int ReadBuf (int /*<<< orphan*/ *,int /*<<< orphan*/ *,int) ; 

UINT ReadBufInt(BUF *b)
{
	UINT value;
	// Validate arguments
	if (b == NULL)
	{
		return 0;
	}

	if (ReadBuf(b, &value, sizeof(UINT)) != sizeof(UINT))
	{
		return 0;
	}
	return Endian32(value);
}