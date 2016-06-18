PGA2311_SPI
===========
This example controls Texas Instruments PGA2311 Stereo Audio Volume Control.
The PGA2311 has 2 potentiometer channels and is an SPI-compatible device.
Controlling it requires that you send a command in the format of two bytes,
one for each channel representing the output level by a value between 0 and 255.
This code is written to be independent of the number of channels on the device,
meaning that it may also be used for sending commands to PGA4311 over SPI since
the device uses a very similar commanding scheme except for the number of channels.
For this, simply alter the value for "const int audioChannels" being "2" with "4".
The code is based on the one written for AD5206, which is publicly available at:
https://www.arduino.cc/en/Tutorial/DigitalPotControl (as of 18 June 2016)
You are free to do whatever you want with this code as long as absolutely no harm
of any kind is done to the author. (Sounds fair, doesn't it?)

Have fun playing it loud!

Written on 18 June 2016 by Tahiro Hashizume

A proud member of Audio Technology Research Club at Tokyo Denki University.
