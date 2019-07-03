#!/bin/bash
make build
stty -f /dev/cu.usbmodem14101 1200
stty stop /dev/cu.usbmodem14101
bossac -e -w -v -b main.bin -p /dev/cu.usbmodem14101
