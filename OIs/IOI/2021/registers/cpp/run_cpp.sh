#!/bin/bash

problem=registers
memory=2097152  # 2GB
stack_size=2097152  # 2GB

ulimit -v "${memory}"
ulimit -s "${stack_size}"
"./${problem}"
