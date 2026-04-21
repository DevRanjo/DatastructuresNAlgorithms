Exercise 3 — Asymptotic Complexity of Sorting Algorithms

Choose the best algorithm (among Insertion Sort, Merge Sort and Quick Sort) to use in the 
following cases, and explain your decision:

• The input array is sorted in descending order:
Merge sort. Since the merge sorting don’t care which order the elements are in at the 
start of the sorting. In comparison to insert, which would have to move every element
to sort, taking a lot of time. 

• The input array is sorted in ascending order:
Insertion sort. Since the elements are already in their position. So, it will take very 
little time and minimal changes. An already sorted array is the best possible case for insertion sort. The complexity becomes O(n) time. 

• All elements in the array are the same:
Insertion sort. Because when going through the list the algorithm will not find any 
changes to make and simply go through the list fast and leave it the same. The same complexity O(n) applies.

• There are both positive and negative numbers in the array:
All are fine to use when there are both positive and negative numbers in the array. It 
will not affect the sorting in any major way. So the sorting algoritms that has the fastest average time complexity (which would be O(n log n)).

Most likely pick Quick sort (random pivot) that doesn't take extra memory like Merge Sort.
[In quick sort you should take caution when you are choosing the pivot when there are negative numbers. ]