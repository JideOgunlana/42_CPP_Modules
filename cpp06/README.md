# Introduction to CPP

[![C++](https://skillicons.dev/icons?i=cpp)](https://skillicons.dev) ~ *(7th module)*   

<br>

```cpp
	float pi = 3.1423;
	int pi_as_int = static_cast<int>(pi);
```

<br/>

## To Learn

- C++ casts
    - static cast
    - dynamic cast
    - reinterpret cast
    - const cast
- Type conversion
- Type reinterpretation
- Qualifier reinterpretation
- Upcasting and downcasting
- Type cast \`operator\`

<br/>

## Tasks include

1. Identifying the right C++ cast to use for each exercise.

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
./build.sh ex00 4.2f
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
