/*
ANSWER:

  A typical two pointer problem. 
  
  Faster Pointer and Slower Pointer..

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode *fast=head;
        ListNode *slow=head;
        
        if( !head || !(head->next) || !(head->next->next))
            return false;
        
        do {
            if( fast -> next && fast -> next -> next) {
                fast = fast -> next -> next;
                slow = slow -> next;
            } else {
                break;
            }        
        } while (fast != slow);
        return fast == slow;
        
    }
};
