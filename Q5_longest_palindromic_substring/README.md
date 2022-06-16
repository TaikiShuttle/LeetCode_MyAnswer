# Longest Palindromic Substring
### Question
Given a string `s`, return the longest palindromic substring in `s`.

### My Solution 1: Find the Center (Anchor)
Notice that we have a palindromic substring, this means that the symmetry yields a center. So what we need to do is treating each character as center and
looking at both sides. The time complexity is $O(n^2)$.
