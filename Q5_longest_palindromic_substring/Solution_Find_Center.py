class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        # Time complexity O(n^2)
        
        # To deal with Leetcode testcases with lots of idenetical characters
        charlist = []
        for element in s:
            if element not in charlist:
                charlist.append(element)
            else:
                continue
                
        if len(charlist) == 1:
            return s
        
        new_s = "#"
        # we need first insert characters '#' to make it odd length
        for i in range(0, len(s)):
            new_s = new_s + s[i] + "#"
        
        maxlen = 1
        LPS = ""
        
        # for each of the character, treat it as center and iterate
        for index, char in enumerate(new_s):
            current_length = 1
            current_string = ""
            i = 0
            while True:
                
                # if we hit the head or the tail of the string, stop
                if (index - i < 0) or (index + i > len(new_s) - 1):
                    break 
                else:
                    # check whether two side are the same
                    if new_s[index - i] == new_s[index + i]:
                        current_length += 2
                        current_string = new_s[index - i] + current_string + new_s[index + i]
                        i += 1
                    else:
                        break
            if current_length > maxlen:
                maxlen = current_length
                LPS = new_s[index - (i - 1): index + (i - 1)]
                
        output = LPS.replace("#","")
        return output
