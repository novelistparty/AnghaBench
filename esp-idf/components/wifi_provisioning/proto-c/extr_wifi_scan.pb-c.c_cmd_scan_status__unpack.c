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
typedef  int /*<<< orphan*/  uint8_t ;
typedef  int /*<<< orphan*/  ProtobufCAllocator ;
typedef  int /*<<< orphan*/  CmdScanStatus ;

/* Variables and functions */
 int /*<<< orphan*/  cmd_scan_status__descriptor ; 
 scalar_t__ protobuf_c_message_unpack (int /*<<< orphan*/ *,int /*<<< orphan*/ *,size_t,int /*<<< orphan*/  const*) ; 

CmdScanStatus *
       cmd_scan_status__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (CmdScanStatus *)
     protobuf_c_message_unpack (&cmd_scan_status__descriptor,
                                allocator, len, data);
}