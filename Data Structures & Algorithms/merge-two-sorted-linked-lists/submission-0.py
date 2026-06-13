# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        cur1 = list1
        cur2 = list2
        head = ListNode()
        res = head

        while cur1 is not None or cur2 is not None:
            if cur2 is None:
                res.next = ListNode(cur1.val)
                cur1 = cur1.next
            elif cur1 is None:
                res.next = ListNode(cur2.val)
                cur2 = cur2.next
            elif cur1.val <= cur2.val:
                res.next = ListNode(cur1.val)
                cur1 = cur1.next
            else:
                res.next = ListNode(cur2.val)
                cur2 = cur2.next

            res = res.next
        
        return head.next
