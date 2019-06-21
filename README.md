# gesture-gloves

Beep boop.


## Projects explained

### mpu6050

The library.

### mpulog

Application to test the mpu6050 sensor (and test if the library actually works).

### gesture-gloves

The gesture-gloves application.


## Useful tips

In bmptk/Makefile.local change
`SERIAL_PORT_DUE := /dev/ttyACM0`
to
`SERIAL_PORT_DUE := $(shell ls /dev | grep ACM)`  

This auto selects the connected micro-controller, the downside to this method is that it doesn't work when multiple ACM devices are connected to the same machine.
