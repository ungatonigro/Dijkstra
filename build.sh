#!/bin/bash
TARGET="main"
g++ -g $(find . -name "*.cpp") -o $TARGET
if [ $? -eq 0 ]; then
    ./$TARGET
fi