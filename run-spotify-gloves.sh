#!/bin/bash
./lpc21isp_hr_osx -termonly /dev/cu.usbmodem14101  2400 12000 | python3 spotify-gloves.py