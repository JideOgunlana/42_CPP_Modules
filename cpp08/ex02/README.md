
## Summary

** MutantStack Class **
> The *`MutantStack`* program uses a MutantStack class, a modified version of std::stack that includes iterators. It offers all the standard stack functions along with the ability to efficiently traverse and manipulate elements using iterators. With MutantStack, you have greater control and flexibility in working with stack data structures.

<br/>

You can modify the main to test.

```cpp
int main() {
    MutantStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);


    // Using iterators
    MutantStack<int>::iterator it;
    for (it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```
