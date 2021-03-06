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
typedef  scalar_t__ uint8_t ;

/* Variables and functions */
 scalar_t__ ISSI_PERSISTENCE ; 
 int /*<<< orphan*/  ISSI_TIMEOUT ; 
 int* g_twi_transfer_buffer ; 
 scalar_t__ i2c_transmit (scalar_t__,int*,int,int /*<<< orphan*/ ) ; 

void IS31FL3731_write_pwm_buffer(uint8_t addr, uint8_t *pwm_buffer) {
    // assumes bank is already selected

    // transmit PWM registers in 9 transfers of 16 bytes
    // g_twi_transfer_buffer[] is 20 bytes

    // iterate over the pwm_buffer contents at 16 byte intervals
    for (int i = 0; i < 144; i += 16) {
        // set the first register, e.g. 0x24, 0x34, 0x44, etc.
        g_twi_transfer_buffer[0] = 0x24 + i;
        // copy the data from i to i+15
        // device will auto-increment register for data after the first byte
        // thus this sets registers 0x24-0x33, 0x34-0x43, etc. in one transfer
        for (int j = 0; j < 16; j++) {
            g_twi_transfer_buffer[1 + j] = pwm_buffer[i + j];
        }

#if ISSI_PERSISTENCE > 0
        for (uint8_t i = 0; i < ISSI_PERSISTENCE; i++) {
            if (i2c_transmit(addr << 1, g_twi_transfer_buffer, 17, ISSI_TIMEOUT) == 0) break;
        }
#else
        i2c_transmit(addr << 1, g_twi_transfer_buffer, 17, ISSI_TIMEOUT);
#endif
    }
}