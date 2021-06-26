#!/bin/bash

problem=registers
grader_name=grader

g++ -std=gnu++17 -O2 -Wall -pipe -o "${problem}" "${grader_name}.cpp" "${problem}.cpp"
