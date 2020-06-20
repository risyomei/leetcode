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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode *tHead = new ListNode(-1,head);
        ListNode *tail = new ListNode(-1,NULL);
        
        int i = 0;
        ListNode *t = tHead;
        ListNode *center = t -> next;
        for( i = 0 ; i < m - 1; i++){
            t = t -> next;                
            center = t -> next;
        }        
        for (; i < n  ; i++) {                    
            ListNode *rn = tail -> next;
            ListNode *tn = t -> next;
            
            tail -> next = tn;
            t -> next = tn -> next;            
            tn -> next = rn;
        }
        
        if(center && t)
            center->next = t -> next;
        if(t  && tail)
            t -> next = tail -> next;
        

        t = tHead -> next;
        delete tail;
        delete tHead;
        return t;
    }
};
