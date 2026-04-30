/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> dict;
        Node dummy(0);
        Node* prev = &dummy;
        Node* ptr = head;

        while (ptr != nullptr) {
            prev->next = new Node(ptr->val);
            dict[ptr] = prev->next;
            ptr = ptr->next;
            prev = prev->next;
        }

        Node* ptr2 = dummy.next;
        ptr = head;

        while (ptr != nullptr && ptr2 != nullptr) {
            ptr2->random = (ptr->random == nullptr) ? nullptr : dict[ptr->random];
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }

        return dummy.next;
    }
};
