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
    ListNode* middleNode(ListNode* head) {
        
        if(!head)
            return NULL;
        if(!(head -> next))
            return head;
        if(!(head -> next -> next))
            return head -> next;
        
        // Length must >= 3 at this point
/*
     1 2 3 4 5 6 7
slow *
Fast *

    1 2 3 4 5 6 7
slow   *
fast     *

    1 2 3 4 5 6 7
slow        *
fast            *

    1 2 3 4 5 6 7 8
slow        *
fast            *
*/
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast -> next != NULL && fast -> next -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        if (fast -> next != NULL)
            return slow -> next;
        return slow;
    }
};
