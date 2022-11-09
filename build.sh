#!/bin/bash

# Build file for control_GPIO.cpp to control_GPIO


echo "Compiling file control_GPIO.cpp to control_GPIO."

g++ control_GPIO.cpp -o control_GPIO

echo "Compilation complete"

echo "Configuring GPIO pin p9.12 to gpio (output) and p8.16 to gpio_pu (input)"

config-pin p9.12 gpio

config-pin p8.16 gpio_pu

echo "Build complete"
