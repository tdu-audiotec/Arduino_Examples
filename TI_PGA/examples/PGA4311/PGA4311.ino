#include <Arduino.h>
#include <TI_PGA.h>
#include <SPI.h>

TI_PGA PGA4311;

uint8_t pinChipSelect = 2;
const int channels = 4;
const uint8_t vol_max = 255;
uint8_t volume[channels] = {0};

void setup() {
    PGA4311.begin_spi(pinChipSelect, channels);
}

void loop() {
    for (int i = 0; i < channels; i++) {
        if (volume[i] == 0) {
            for (uint8_t j = 0; j < vol_max; j++) {
                volume[i] = j;
                PGA4311.write(volume);
            }
        }
        if (volume[i] == vol_max) {
            for (uint8_t j = vol_max; j > 0; j--) {
                volume[i] = j;
                PGA4311.write(volume);
            }
        }
    }
}