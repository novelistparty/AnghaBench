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

/* Variables and functions */
 int FALSE ; 
 int _L ; 
 int* ascii ; 

int Curl_islower(int c)
{
  if((c < 0) || (c >= 0x80))
    return FALSE;
  return (ascii[c] & (_L));
}