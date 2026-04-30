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
    void reorderList(ListNode* head) {
        ListNode* ptr = head;
        deque<ListNode*> arr;
        while (ptr != nullptr) {
            arr.push_back(ptr);
            ptr = ptr->next;
        }
        arr.pop_front();
        ptr = head;
        while (!arr.empty()) {
            ptr->next = arr.back();
            arr.pop_back();
            ptr = ptr->next;
            if (!arr.empty()) {
                ptr->next = arr.front();
                arr.pop_front();
                ptr = ptr->next;
            }
        }
        ptr->next = nullptr;
    }
};
