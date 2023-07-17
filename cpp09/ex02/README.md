
## Summary
### PmergeMe
> The *`PmergeMe`* program applies merge-insert sort alogrithm on two separate containers and provides the time it takes to complete sorting on both.


#### The program must adhere to these rules:
- the program must be able to use a positive integer sequence as argument.
- the program must use the merge-insert sort algorithm to sort the positive integer
sequence.
- if an error occurs during program execution, an error message should be displayed
on the standard output.

#### Sample


```
./PmergeMe 10 9 8 7 6 5 4 3 2 1

Before: 10 9 8 7 6 5 4 3 2 1 

After:
DEQUE container => 1 2 3 4 5 6 7 8 9 10 
Time to process a range of 10 elements with std::deque: 310µs

After:
VECTOR container =>1 2 3 4 5 6 7 8 9 10 
Time to process a range of 10 elements with std::vector: 206µs


```


