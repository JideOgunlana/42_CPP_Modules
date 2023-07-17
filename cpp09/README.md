# Introduction to CPP

[![C++](https://skillicons.dev/icons?i=cpp)](https://skillicons.dev) ~ *(10th module)*\
The final module to C++ introduction   

<br>

```cpp
    //Sequence containers
    #include <array>
    #include <vector>
    #include <deque>
    #include <list>
    #include <forward_list>

    // Container Adaptors
    #include <stack>
    #include <queue>
    #include <priority_queue>

    // Associative Containers
    #include <set>
    #include <multiset>
    #include <map>
    #include <multimap>

    // Unordered Associative Containers
    #include <unordered_set>
    #include <unordered_multiset>
    #include <unordered_map>
    #include <unordered_multimap>
```

<br/>

## To Learn

- C++ Standard Containers
<br/>

## Tasks include

Using C++ Standard Containers for each exercise, where every container used for consequent exercises must be different.
1. Bitcoin Exchange
2. Reverse Polish Notation (RPN)
3. PMergeMe
> Only one container is to be for each exercise, except the last where only two containers are allowed
<br/>

## USAGE

Here are instructions for compiling exercises in this project:

1. without parameters, compile all exercises with the <span style="color:MediumSeaGreen">"*build.sh*"</span> script
```bash
./build.sh
```
<br/>

2. with parameter ex00 or ex01 or ex[x] compile and run a specific exercise.
```bash
./build.sh ex00
```
<br/>

3. With parameter <span style="color:DeepSkyblue">clean</span> - delete all object files
```bash
./build.sh clean
```
<br/>

4. With parameter <span style="color:DeepSkyblue">clean</span> and an exercise's directory - delete  object files of that directory
```bash
./build.sh clean ex00
```
<br/>

5. With parameter <span style="color:DeepSkyblue">fclean</span> - delete all object files and executables
```bash
./build.sh fclean
```
<br/>

6. With parameter <span style="color:DeepSkyblue">fclean</span> and an exercise's directory - delete all object files and executables of that directory
```bash
./build.sh fclean ex00
```
<br/>


<span style="color:orange">__Alternatively__ </span>you can compile specific exercises by navigating to their respective directories and using their makefiles
```bash
cd ex00 && make
