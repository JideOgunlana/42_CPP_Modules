# Introduction to CPP

[![C++](https://skillicons.dev/icons?i=cpp)](https://skillicons.dev) ~ *(2nd module)*   



<br/>

## To Learn

- dynamic memory allocation (new and delete)
- pointers to member attributes and functions
- references
	- passing parameters by reference
	- returns by reference

<br/>

## Tasks include

1. Deciding whether to instantiate a class on the heap or stack
2. Creating a contiguous block of memory for an array of instances in a single allocation.
3. Utilizing references in C++.
4. Performing file manipulation operations.

<br/>

## USAGE

Here are instructions for compiling exercises in this project:

1. without parameters, compile all exercises with the <span style="color:MediumSeaGreen">"*build.sh*"</span> script
```console
./build.sh
```
2. With parameter <span style="color:DeepSkyblue">clean</span> - delete all object files
```console
./build.sh clean
```
3. With parameter <span style="color:DeepSkyblue">fclean</span> - delete all object files and executables
```console
./build.sh fclean
```

<span style="color:orange">__Alternatively__ </span>you can compile specific exercises by navigating to their respective directories and using their makefiles
```console
cd ex00 && make