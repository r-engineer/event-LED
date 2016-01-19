#ifndef BLINKY_LED_H 
#define BLINKY_LED_H

#include "scheduler.h"
#include <stdint.h>

const uint8_t LED_ON = 1;
const uint8_t LED_OFF = 0;


class blinky_led : public polled_event
{
public:
	blinky_led(uint8_t io, uint16_t on_off_time, uint8_t on_val );
	virtual void init();
	virtual void execute();
	void set_on_off_time();
	void set_on_off_time(uint16_t on_off_time);
	uint16_t get_on_off_time() {return count_start;}
private:
	uint16_t bl_on_off_default;
	uint8_t bl_gpio;
	uint8_t bl_on_value;
	uint8_t bl_off_value;
	uint8_t bl_led_state;
	void set_led_state(uint8_t state);
};	
	
#endif