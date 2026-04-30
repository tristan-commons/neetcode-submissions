/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode head;
        ListNode* prev = &head;


        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                prev->next = p1;
                p1 = p1->next;
            } else {
                prev->next = p2;
                p2 = p2->next;
            }
            prev = prev->next;
        }

        prev->next = (p1 != nullptr) ? p1 : p2;

        return head.next;
    }
};
