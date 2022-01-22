#!/bin/bash

rm -rf ../bin/led_blink64
mkdir ../bin/led_blink64
aarch64-linux-gnu-gcc -nostartfiles -march=armv8-a+crc -mcpu=cortex-a53 -DRPI3 ../src/led_blink/led_blink.c -o ../bin/led_blink64/led_blink64.elf
aarch64-linux-gnu-objcopy ../bin/led_blink64/led_blink64.elf -O binary ../bin/led_blink64/led_blink64.img
