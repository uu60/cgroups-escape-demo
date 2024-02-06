#!/bin/bash

# Infinite loop to generate workload
while true; do
    # Listing all loaded modules in the host system
    # This command is just an example to simulate workload
    lsmod > /dev/null
    # Optional: add sleep to slightly reduce the impact
    sleep 1
done