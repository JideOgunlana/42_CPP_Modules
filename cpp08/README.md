# Introduction to CPP

[![C++](https://skillicons.dev/icons?i=cpp)](https://skillicons.dev) ~ *(8th module)*   

<br>

```cpp
    #include <algorithm>
    #include <vector>
    #include <iostream>

    int main(void) {
        std::vector<std::string> users;

        users.push_back("Jarvis");
        users.push_back("Gambit");
        std::cout << users[0] << std::endl;
        return 0;
    }

```

<br/>

## To Learn

- C++ STL
<br/>

## Tasks include

1. Using C++ STL algorithm, templated containers, and iterators

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
