class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashtable = {} # new dict, used as a hashtable

        # built the hashtable
        for element in nums:
            hashtable[element] = []
        for i, element in enumerate(nums):
            hashtable[element].append(i)

        # search for answers
        for kvpair_num in hashtable:
            if target - kvpair_num in hashtable:
                if target == 2*kvpair_num:              # two numbers are equal, like 3+3=6
                    if len(hashtable[kvpair_num]) == 1: # rule out the number itself
                        continue
                    else:
                        return [hashtable[kvpair_num][0], hashtable[kvpair_num][1]]
                else:
                    return [hashtable[kvpair_num][0],hashtable[target - kvpair_num][0]]
            else:
                continue
