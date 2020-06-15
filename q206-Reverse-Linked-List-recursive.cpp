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

    ListNode* finalhead = nullptr;
    
    void reverse(ListNode* head) {
        
        if(head == NULL){
            return;
        }
        
        if(head -> next == NULL) {
            finalhead = head;
            return;
        }
        
        ListNode* p = head;
        ListNode* pn = head -> next;
        
        reverse(head->next);
        
        pn -> next = p;
        p -> next = NULL;
        return;
     }
    
    ListNode* reverseList(ListNode* head) {
        reverse(head);
        return finalhead;  
    }
};
