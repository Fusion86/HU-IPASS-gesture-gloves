#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
#
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES :=

# header files in this project
HEADERS :=

# other places to look for files for this project
SEARCH  := ../../lib/mpu6050 ../../lib/hwlib-extra ../../lib/gesture-gloves
# set RELATIVE to the next higher directory
# and defer to the Makefile.* there
RELATIVE := ../..
include $(RELATIVE)/lib/mpu6050/Makefile.inc
include $(RELATIVE)/lib/hwlib-extra/Makefile.inc
include $(RELATIVE)/lib/gesture-gloves/Makefile.inc
include $(RELATIVE)/Makefile.due
