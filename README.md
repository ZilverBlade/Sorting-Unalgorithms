Normally, in computer science we try to find the fastest algorithms, whether it be sorting, computing, and the such.

But what if we didn't try to be efficient, but the exact opposite? What is the worst possible way to sort an array?

### Stooge sort
A very slow sorting algorithm that works based on sorting 2/3 of the left elements, and then the right elements, and left again, recursively.
Visualised it's very slow, but unfortunately it only has a time complexity of O(n^(log 3 / log 1.5)) (approximately O(n^2.709))

##### Can we go slower?

### Slow sort
This is takes inspiration from the blazingly fast merge sort, but instead of merging the sorted arrays, it will only swap the largest elements within the array, 
making sure that the largest element is on the end of the array, followed by recursively slow sorting the rest of the array (except for the last element). 
Now this sounds very slow, which it is, but again, unforunately has the same time complexity as Stooge Sort! :(

##### Let's be creative

### Lookup Sort
What if we created a dictionary, that contains every possible array in the universe as the key, and placed the corresponding sorted array as the value? Surely it would be an O(1) time complexity?
```
| [1, 2, 0] -> [0, 1, 2] |
| [0, 2, 1] -> [0, 1, 2] |
| [2, 0, 1] -> [0, 1, 2] |
| [2, 1, 0} -> [0, 1, 2] |
```
It would be extremely impractical however, as it has a space complexity of O(∞). 
The actual space complexity, assuming we strictly use 32 bit integer for our array, would be (where n is the maximum array length):
* `O( (2^32)^(n) ))*`
If we were to even implement this sorting algorithm for an array of length 1, it would require at least 51GB of memory! (Assuming a key size of 8 bytes and the array size being exactly 4 bytes)

##### Can we maybe try going for the worst time complexity?

### Permute Sort
An array of objects can be sorted in different fashions
For instance, an array `[0, 1, 2]` can also be listed as `[1, 0, 2]`, `[2, 1, 0]`, `[2, 0, 1]`, `[1, 2, 0]`, `[0, 2, 1]`. In total, there are `N!` possible ways to organise an array, where N is the array length.
What's interesting is that at least one combination of elements is guaranteed to be sorted! So, what's our algorithm?
Just try every single combination until it's sorted!
The time complexity is thus `O(n!)`

##### A twist on bogo sort

### Parallel Bogo Sort
Bogo sort is extremely inefficient, it has an average time complexity of O(n*n!)! But we can make it faster, by making use of multiple threads! The great thing is, it's GPU compatible!
It works as follows: 
* On one thread, we first bogosort the entire array.
* If it's not sorted, then we create 2 new threads, and copy the bogo sorted array onto them.
* We continue this recursively until one thread has a sorted array, and we notify all the other threads that the array is sorted!

