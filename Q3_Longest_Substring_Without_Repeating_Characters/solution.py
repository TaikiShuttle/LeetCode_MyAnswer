class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        # create a dict to mark down the last position of certain characters. e.g. a:5, b:4
        last_position = {}
        
        # information about current longest substr and current substr
        longest_len = 0
        
        # begin to iterate
        for i,character in enumerate(s):
            # base case
            if i == 0:
                last_position[character] = 0
                longest_len = 1
            else:
                # if we meet a new character, then we update its position and check length
                if character not in last_position.keys():
                    last_position[character] = i
                    if i - min(last_position.values()) + 1 > longest_len:
                        longest_len = i - min(last_position.values()) + 1
                else:
                    # first kick out all the characters shown before this character
                    new_dict = {}
                    for element in last_position:
                        if last_position[element] >= last_position[character]:
                            new_dict[element] = last_position[element]
                    last_position = new_dict
                    
                    
                    # check whether the substring between these two characters is longer than longest_len
                    if i - last_position[character] > longest_len:
                        longest_len = i - last_position[character]
                        
                    # replace the current position
                    last_position[character] = i
                    
        return longest_len
            
