#include "blinky_led.h"
#include "Arduino.h"

blinky_led::blinky_led(uint8_t io, uint16_t on_off_time, uint8_t on_val )
: polled_event(on_off_time)
{
	
	bl_gpio = io;
	bl_on_value = on_val;
	if(bl_on_value)
		bl_off_value = 0;
	else
		bl_off_value = 1;
}

void blinky_led::init()
{
	pinMode(bl_gpio, OUTPUT);
	
	//turn the led off.
	set_led_state(LED_OFF);
}

void blinky_led::set_led_state(uint8_t state)
{
	if(state == LED_ON)
	{
		digitalWrite(bl_gpio, bl_on_value);
		bl_led_state = LED_ON;
	}
	else
	{
		digitalWrite(bl_gpio, bl_off_value);
		bl_led_state = LED_OFF;
	}
}

void blinky_led::set_on_off_time(uint16_t on_off_time)
{
	//base class
	set_counter(on_off_time);
}

void blinky_led::execute()
{
	if(bl_led_state == LED_ON)
		set_led_state(LED_OFF);
	else
		set_led_state(LED_ON);
	
	reset_counter();
}