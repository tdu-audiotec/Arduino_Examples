#include "TI_PGA.h"
#include <SPI.h>

//
//class TI_PGA{
//public:
//char statmsg_c[80];
//boolean value_bit[4][8] = {{0},{0}};
void TI_PGA::begin_gpio(uint8_t pin_cs, uint8_t channel, uint8_t pin_clk, uint8_t pin_miso, uint8_t pin_mosi) {
    statmsg_s = {""};
    if (!_pgaInit) {
        _pin_cs = pin_cs;
        _channel = channel;
        _pin_clk = pin_clk;
        _pin_miso = pin_miso;
        _pin_mosi = pin_mosi;
        pinMode(_pin_cs, OUTPUT);
        digitalWrite(_pin_cs, HIGH);
        pinMode(_pin_clk, OUTPUT);
        pinMode(_pin_mosi, OUTPUT);
        pinMode(_pin_miso, INPUT);
        _pgaInit = true;
        _pgaSpi = false;
        statmsg_s = "GPIO mode in operation.";
    } else if (_pgaSpi) {
        statmsg_s = "SPI mode in operation. Cannot start in GPIO mode.";
    }
}

void TI_PGA::begin_spi(uint8_t pin_cs, uint8_t channel) {
    statmsg_s = {""};
    if (!_pgaInit) {
        _pin_cs = pin_cs;
        _channel = channel;
        pinMode(_pin_cs, OUTPUT);
        digitalWrite(_pin_cs, HIGH);
        _pin_clk = _pin_miso = _pin_mosi = 255;
        SPI.begin();
        SPI.setDataMode(SPI_MODE0);
        _pgaInit = true;
        _pgaSpi = true;
        statmsg_s = "SPI mode in operation.";
    } else if (!_pgaSpi) {
        statmsg_s = "GPIO mode in operation. Cannot start in SPI mode.";
    }
}

void TI_PGA::write(uint8_t value[]) {
    const uint8_t ch_total = sizeof(value)/ sizeof(value[0]);
    static uint8_t old_value[ch_total];
    static boolean value_changed;
    for (uint8_t i = 0; i < ch_total; i++) {
        if (old_value[i] != value[i]) {
            value_changed = true;
        }
    }
    if (value_changed) {
        noInterrupts();
        digitalWrite(_pin_cs, LOW);
        if (TI_PGAtransfer(value, _pgaSpi)) {
            digitalWrite(_pin_cs, HIGH);
            interrupts();
            for (uint8_t i = 0; i < ch_total; i++) {
                old_value[i] = value[i];
            }
            value_changed = false;
        }
    }
}

void TI_PGA::status(void) {
    statmsg_s.toCharArray(statmsg_c, (statmsg_s.length() + 1));
}

//private:
//boolean _pgaInit = false;
//boolean _pgaSpi = false;
//uint8_t _pin_clk, _pin_miso, _pin_mosi, _pin_cs, _channel;
//String statmsg_s = "";



boolean TI_PGA::TI_PGAtransfer(uint8_t data[], boolean spi_mode) {
    boolean success = false;
    uint8_t ch_order;
    uint8_t ch_total = sizeof(data)/ sizeof(data[0]);
    if (spi_mode) {
        for (uint8_t i = 0; i < ch_total; i++) {
            ch_order = ch_total - i - 1;
            SPI.transfer(data[ch_order]);
        }
        success=true;
    } else if (!spi_mode){
        for (uint8_t i = 0; i < ch_total; i++) {
            ch_order = ch_total - i - 1;
            for (uint8_t j = 0; j < 8; j++) {
                uint8_t bit_order = sizeof(data[0]) - j - 1;
                digitalWrite(_pin_clk, LOW);
                digitalWrite(_pin_mosi, bitRead(data[ch_order], bit_order));
                digitalWrite(_pin_clk, HIGH);
                value_bit[i][bit_order]=bitRead(data[ch_order], bit_order);
            }
        }
        success=true;
    }
    return success;
}

//};