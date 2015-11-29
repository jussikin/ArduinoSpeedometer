# ArduinoSpeedometer
Simple speedometer. Arduino + tm1637 4 digit display + serial gps module.

## Manifest:
1. Arduino Nano
2. Cheap tm1637 led tube display unit
3. Neoblox 6M serial gps module unit

## Operation:
When connected to usb power, Arduino will start receiwing data from GPS unit. Soon as device gets gps fix it will start showing local time in finland. If device is moving faster than 10 kmh speed in kmh speed will be displayed instead of time.

## Wiring:
Gps and Display modules are wired for power and grond from nano. Singnaling into display is on pins (CLK12,and DIO11), gps module serial line is connected to pins 2,3.
