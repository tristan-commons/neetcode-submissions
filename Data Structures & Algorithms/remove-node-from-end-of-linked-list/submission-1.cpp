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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int diff = 0;
        ListNode* left = head;
        ListNode* right = head;

        while (diff < n) {
            if (right == nullptr) {
                return nullptr;
            }
            right = right->next;
            diff++;
        }

        if (right == nullptr) return head->next;

        while (right->next != nullptr) {
            right = right->next;
            left = left->next;
        }

        ListNode* toDelete = left->next;
        left->next = toDelete->next;
        delete toDelete;

        return head;
    }
};
