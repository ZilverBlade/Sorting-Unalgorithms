Normally, in computer science we try to find the fastest algorithms, whether it be sorting, computing, and the such.

But what if we didn't try to be efficient, but the exact opposite? What is the slowest possible way to sort an array?
Naturally relying on randomisation is the simplest approach, but that's cheating, what is actually the slowest way to sort an array, with a guaranteed upper bound?

#### Stooge sort
A very slow sorting algorithm that works based on sorting 2/3 of the left elements, and then the right elements, and left again, recursively.
Visualised it's very slow, but unfortunately it only has a time complexity of O(n^(log 3 / log 1.5)) (approximately O(n^2.709))

##### Can we go slower?

#### Slow sort
This is takes inspiration from the blazingly fast merge sort, but instead of merging the sorted arrays, it will only swap the largest elements within the array, 
making sure that the largest element is on the end of the array, followed by recursively slow sorting the rest of the array (except for the last element). 
Now this sounds very slow, which it is, but again, unforunately has the same time complexity as Stooge Sort! :(

##### Let's be creative

#### Lookup Sort
What if we created a dictionary, that contains every possible array in the universe as the key, and placed the corresponding sorted array as the value? Surely it would be an O(1) time complexity?
It would be extremely impractical however, as it has a space complexity of O(∞). 
The actual space complexity, assuming we strictly use 32 bit integer for our array, would be (where n is the maximum array length):
* `O( (2^32)^(n) ))*`
If we were to even implement this sorting algorithm for an array of length 1, it would require at least 51GB of memory! (Assuming a key size of 8 bytes and the array size being exactly 4 bytes)

##### Can we maybe try going for the worst time complexity?

#### Card-Counting Sort
