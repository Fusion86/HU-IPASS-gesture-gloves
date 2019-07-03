# gesture-gloves

Beep boop.


## Projects explained

### lib/mpu6050

Basic library to read values from a MPU-6050 sensor (on a GY-521 breakout board).

### lib/hwlib-extra

Extensions for hwlib. Currently only adds float printing support to `hwlib::cout`.

### src/mpulog

Application to test the MPU-6050 sensor (and test if the library actually works).

### src/gesture-spotify

The gesture-gloves application, detects simple hand gestures and translates those to spotify actions (e.g. pausing, volume up/down, next track). To use this you need to pipe the Arduino Due's output to spotify-gloves.py.

### src/hwlib-extra-test

Test (well, manual tests) for hwlib-extra.


## Example usage

This only works on macOS (because AppleScript is used to emulate media key presses).
The python script acts like a MITM because it looks at the input before printing it to your stdout (terminal usually).
When the script detects an `action: ...` it'll execute the task linked to that action (e.g. for `toggle_play_pause` the media play/pause key will be pressed).

```sh
# If you connect the Due directly to your mac
# You also need to install the driver, see https://arduino.stackexchange.com/a/17358
./run-spotify-gloves.sh
```


## Useful tips

In bmptk/Makefile.local change
`SERIAL_PORT_DUE := /dev/ttyACM0`
to
`SERIAL_PORT_DUE := $(shell ls /dev | grep ACM)`

This auto selects the connected micro-controller, the downside to this method is that it doesn't work when multiple ACM devices are connected to the same machine.

lpc21isp_hr_osx is compiled on 10.14.3, [source](https://github.com/wovo/bmptk/tree/master/tools/lpc21isp_197).
