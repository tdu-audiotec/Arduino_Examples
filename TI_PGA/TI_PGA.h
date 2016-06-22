#ifndef _TI_PGA_H_
#define _TI_PGA_H_
    
#if ARDUINO >= 100
#include <Arduino.h>
#else
#include <WProgram.h>
#endif
    
class TI_PGA{
public:
    char statmsg_c[80];
    boolean value_bit[4][8] = {{0},{0}};
    void begin_gpio(uint8_t pin_cs, uint8_t channel, uint8_t pin_clk, uint8_t pin_miso, uint8_t pin_mosi);
    void begin_spi(uint8_t pin_cs, uint8_t channel);
    void write(uint8_t value[]);
    void status(void);
private:
    boolean _pgaInit = false;
    boolean _pgaSpi = false;
    uint8_t _pin_clk, _pin_miso, _pin_mosi, _pin_cs, _channel;
    String statmsg_s = "";
    boolean SPItransfer(uint8_t data[], boolean spi_mode);
};
    
#endif
    
