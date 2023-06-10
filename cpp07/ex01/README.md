<h2><u>Summary</u></h2>

> *ex01 creates a program named \"Iter\" which uses an implemented template function 'iter' that iterates through an array. The template function 'iter' takes 3 parameters, the first is the address of the array, the second is the length of the array, and the third is the function that will be called on every element*

<br>

```cpp
    std::string fullName[2] = {"John", "Bekins"};

    ::iter(fullName, 2, print);
```
