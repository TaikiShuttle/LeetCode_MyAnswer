# Two Sum
### Question
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

### My Solution
Use Hashtable to store value. For each of the element in the Hashtable, check if `target - element` is also in the Hashtable.

### Details to Consider
1. If two numbers are same, like `3+3=6`, we need to distinguish the index of two `3`s. I decide to use a list in each HashTable bucket to store all the index of certain number.
2. Use `num` as `Key` and its index as `value`. Otherwise we may have some difficulty to output the result?
