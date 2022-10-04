# Median of two sorted array
### Question
Given two sorted arrays `nums1` and `nums2` of size `m` and `n` respectively, return the median of the two sorted arrays.

The overall run time complexity should be $\mathcal{O}(log (m+n))$.

### Answer (not mine, I fail)
One fact we can observe is that, if we compare two numbers from `nums1` and `nums2` and kick out one. Then all the numbers before that candidate in that array will also
be kicked out -- They are too small.

Based on this, we can use a recursion to find the `k`th biggest element, which is generalized.
