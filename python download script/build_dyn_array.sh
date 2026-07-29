#!/bin/sh
mkdir -p build
python3 main.py
cd build
cmake .
cmake --build .
sudo cmake --install .