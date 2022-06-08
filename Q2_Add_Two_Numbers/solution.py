# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        if (l1 == None) and (l2 != None):
            return l2
        elif (l1 != None) and (l2 == None):
            if l1.val >= 10:
                if l1.next == None:
                    l1.next = ListNode(val = 1, next = None)
                    l1.val -= 10
                    return l1
                else:
                    l1.next.val += 1
                    result = ListNode(val = l1.val - 10, next = self.addTwoNumbers(l1.next, None))
                    return result
            else:
                return l1
        elif (l1 == None) and (l2 == None):
            return None
        elif (l1 != None) and (l2 != None):
            # consider no overflow case
            if l1.val + l2.val < 10:
                result = ListNode(val = l1.val + l2.val, next = self.addTwoNumbers(l1.next, l2.next))
            # consider overflow case, add overflow to l1.next
            else:
                residual = l1.val + l2.val - 10
                # print(residual)
                # if l1.next = None, we create a new node with value 1
                if l1.next == None:
                    l1.next = ListNode(val = 1, next = None)
                # else l1.next.val + 1
                else:
                    l1.next.val += 1
                # print(l1.next,l2.next)
                result = ListNode(val = residual, next = self.addTwoNumbers(l1.next, l2.next))
                # print("after l1",l1,"after l2",l2)
            return result
            
            
