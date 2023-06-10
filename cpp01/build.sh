#!/bin/bash

# Define the subdirectories
SUBDIRS="ex00 ex01 ex02 ex03 ex04 ex05"

# Compile the selected subdirectories
if [ "$1" == "" ]; then
    for DIR in $SUBDIRS; do
        cd $DIR
        make
        cd ..
    done
fi

if [ "$1" == "clean" ]; then
    for DIR in $SUBDIRS; do
        cd $DIR
        make clean
        cd ..
    done
fi


if [ "$1" == "fclean" ]; then
    for DIR in $SUBDIRS; do
        cd $DIR
        make fclean
        cd ..
    done
fi