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
typedef  int uint8_t ;

/* Variables and functions */
 int DDRB ; 
 int DDRD ; 
 int PORTB ; 
 int PORTD ; 
 int USB_LED_CAPS_LOCK ; 

void led_set(uint8_t usb_led)
{
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // output low
        DDRB |= (1<<0);
        PORTB &= ~(1<<0);
        DDRD |= (1<<5);
        PORTD &= ~(1<<5);
    } else {
        // Hi-Z
        DDRB &= ~(1<<0);
        PORTB &= ~(1<<0);
        DDRD &= ~(1<<5);
        PORTD &= ~(1<<5);
    }
}