## Algorithm 2019 HW2 : Quick sort, insertion sort and Mix

------

### HW Description

1. Use C or C++ to implement an insertion sorting algorithm that accepts an input file with the first line indicating the number of keys to be sorted, followed by the list of keys with one line for each key. The algorithm should generate an output file with the number of keys sorted in the first line, followed by the sorted keys with one key in each line.

2. Write a quicksort program in C with the same input/output formats as those in Problem 1.

3. Generate an input that has nearly sorted 10000 numbers. Compare the execution time of your two algorithms in Problems 1 and 2 to see which algorithm runs faster.
4. Implement the algorithm described in the exercise **7.4-5**. Check to see if it is faster than both insertion sort and quicksort algorithms by giving the CPU time for the algorithms.
> **7.4-5**: We can improve the running time of quicksort in practice by taking advantage of the fast running time of insertion sort when its input is "nearly" sorted. Upon calling quicksort on a subarray with fewer than k elements, let it simply return without sorting the subarray. After the top-level call to quicksort returns, run insertion sort on the entire array to finish the sorting process. Argue that this sorting algorithm runs in O(nk+nlg(n/k)) expected time. How should we pick k, both in theory and practice?

> Note: You can generate an input data file with numbers from 1, 2, to 10000 first and then randomly exchange a small number of pairs of numbers to create a nearly sorted set of numbers. 


------
