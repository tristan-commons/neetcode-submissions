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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        bool carry = false;
        ListNode resultHead = ListNode();
        ListNode* resultPtr = &resultHead;

        while (ptr1 != nullptr || ptr2 != nullptr) {
            int digitSum = 0;

            if (ptr1 == nullptr) {
                digitSum = ptr2->val;
            } else if (ptr2 == nullptr) {
                digitSum = ptr1->val;
            } else {
                digitSum = ptr1->val + ptr2->val;
            }

            if (carry) {
                digitSum++;
                carry = false;
            }

            if (digitSum >= 10) {
                digitSum -= 10;
                carry = true;
            }

            resultPtr->next = new ListNode(digitSum);
            resultPtr = resultPtr->next;
            ptr1 = ptr1 != nullptr ? ptr1->next : ptr1;
            ptr2 = ptr2 != nullptr ? ptr2->next : ptr2;
            cout << "Digit Sum: " << resultPtr->val << "\n";
        }

        if (carry) {
            resultPtr->next = new ListNode(1);
        }

        return resultHead.next;
    }
};
