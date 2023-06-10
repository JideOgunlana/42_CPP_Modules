# Introduction to CPP

[![C++](https://skillicons.dev/icons?i=cpp)](https://skillicons.dev) ~ *(5th module)*   



<br/>

## To Learn

- Subtype Polymorphism
- Abstract Classes
- Interface

<br/>

## Tasks include

1. Changing the behaviour of a derived class function by polymorphism (virtual keyword used).
2. Defining a base class that can not be instantiated but acts as a blue print to implement derived classes (concrete classes).
3. Creating a deep copy of an object.

<br/>

## USAGE

Here are instructions for compiling exercises in this project:

1. without parameters, compile all exercises with the <span style="color:MediumSeaGreen">"*build.sh*"</span> script
```console
./build.sh
```
2. with parameter ex00 or ex01 or ex02, compile and run a specific exercise
```console
./build.sh ex00
```
3. With parameter <span style="color:DeepSkyblue">clean</span> - delete all object files
```console
./build.sh clean
```
4. With parameter <span style="color:DeepSkyblue">fclean</span> - delete all object files and executables
```console
./build.sh fclean
```

<span style="color:orange">__Alternatively__ </span>you can compile specific exercises by navigating to their respective directories and using their makefiles
```console
cd ex00 && make
