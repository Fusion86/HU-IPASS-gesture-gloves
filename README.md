# gesture-gloves

Beep boop.


## Projects explained

### mpu6050

Basic library to read values from a MPU-6050 sensor.

### mpulog

Application to test the MPU-6050 sensor (and test if the library actually works).

### gesture-gloves

The gesture-gloves application, detects hand gestures. Requires a MPU-6050 that is duct taped to a glove.

## hwlib-extra

Extensions for hwlib. Currently only adds float printing support to `hwlib::cout`.

## hwlib-extra-test

Test (well, manual tests) for hwlib-extra. 


## Useful tips

In bmptk/Makefile.local change
`SERIAL_PORT_DUE := /dev/ttyACM0`
to
`SERIAL_PORT_DUE := $(shell ls /dev | grep ACM)`  

This auto selects the connected micro-controller, the downside to this method is that it doesn't work when multiple ACM devices are connected to the same machine.
