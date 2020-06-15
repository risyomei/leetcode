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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* p = head;
        ListNode* tHead = new ListNode();        
        
        while (p!=nullptr) {
            
            ListNode* tp = p;
            p = p -> next;
            
            tp -> next = tHead -> next;
            tHead -> next = tp;            
        }
        return tHead -> next; 
    }
};
