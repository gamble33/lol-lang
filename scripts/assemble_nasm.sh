#!/bin/bash

name=$1

nasm -f elf64 -o $name.o $name.asm
ld $name.o -o $name
./$name
