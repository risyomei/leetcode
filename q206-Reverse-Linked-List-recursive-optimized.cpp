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
        
        if(head == NULL){
            return NULL;
        }
        
        if(head -> next == NULL) {
            return head;
        }
        
        // Cache p in recursive stack
        ListNode* p = head;   
        
        // Always return t, as that's the last node.
        ListNode *t = reverseList(head->next);
        
        // Reverse 
        p -> next -> next = p;
        p -> next = NULL;        
        
        return t;
    }
};
