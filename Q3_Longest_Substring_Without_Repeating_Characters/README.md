# Longest Substring Without Repeating Characters
### Question
Given a string `s`, find the length of the longest substring without repeating characters.
### My solution
1.  Use a hash table to mark down the last time of that each character shows in the list.
2.  Each time we see a repeated character, kick out all the character in the hash table with showing position before that character. Check and compare the length of substring with current longest one. Then update the last shown position.
3.  Pursue $O(kn) = O(n)$ time complexity. Traverse the whole list once. In the worse case, travese te whole list once and then travese the hash table once.
### Note
1. `Python 3` cannot change the size of dict/list during for loop. You can create new dict and copy the element you want into the new dict.
