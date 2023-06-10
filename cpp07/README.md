# Introduction to CPP

[![C++](https://skillicons.dev/icons?i=cpp)](https://skillicons.dev) ~ *(8th module)*   

<br>

```cpp
    template <typename T> // Template definition
        
    T max(T x, T y) {
        return (x >= y) ? x : y;
    }
```

<br/>

## To Learn

- C++ Templates
    - Template functions
    - Template classes
    - Template Defaults
    - Template Specialization (Partial / Full Specialization)

<br/>

## Tasks include

1. Implementing a function template
2. Developing a class template of a given behaviour

<br/>

## USAGE

Here are instructions for compiling exercises in this project:

1. without parameters, compile all exercises with the <span style="color:MediumSeaGreen">"*build.sh*"</span> script
```console
./build.sh
```
<br/>

2. with parameter ex00 or ex01 or ex[x] compile and run a specific exercise.
```console
./build.sh ex00
```
<br/>

3. With parameter <span style="color:DeepSkyblue">clean</span> - delete all object files
```console
./build.sh clean
```
<br/>

4. With parameter <span style="color:DeepSkyblue">clean</span> and an exercise's directory - delete  object files of that directory
```console
./build.sh clean ex00
```
<br/>

5. With parameter <span style="color:DeepSkyblue">fclean</span> - delete all object files and executables
```console
./build.sh fclean
```
<br/>

6. With parameter <span style="color:DeepSkyblue">fclean</span> and an exercise's directory - delete all object files and executables of that directory
```console
./build.sh fclean ex00
```
<br/>


<span style="color:orange">__Alternatively__ </span>you can compile specific exercises by navigating to their respective directories and using their makefiles
```console
cd ex00 && make
