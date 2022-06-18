# Longest Palindromic Substring
### Question
Given a string `s`, return the longest palindromic substring in `s`.

### My Solution 1: Find the Center (Anchor)
Notice that we have a palindromic substring, this means that the symmetry yields a center. So what we need to do is treating each character as center and
looking at both sides. The time complexity is $O(n^2)$.

### My solution 2: Manacher's Algorithm
This algorithm uses the symmetry of the palindromic substring. It uses a helper array to markdown the longest palindromic substring length at each position, and calculate the right hand side value based on the mirrored-place. In this way, it only needs to iterate the array once, leading to a time complexity of $O(n)$. But the boundary conditions are more complicated than solution 1.
