# Add Two Numbers
### Question
You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order**, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself

### My Solution
1. Use Recursion
2. If we meet overflow, add to the `list1.next`, if `list1.next = None`, create a new node

### Note
1. My answer is really slow
2. No need to use recursion
3. Claim a global `carry` only cost you 1 bit, so please consider the overflow separately. Don't follow my idea!
