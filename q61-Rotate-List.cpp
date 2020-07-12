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
    ListNode* rotateRight(ListNode* head, int k) {
        
        int num = 0;
        ListNode* p = nullptr;
        ListNode* tail = nullptr;
        ListNode* tempHead = new ListNode(0,head);
        
        // Find tail, Find total num
        p = head;
        while( p != nullptr) {
            tail = p;
            p = p -> next;
            num ++;
        }
        
        if (num == 0){
            return head;
        } else if (k % num == 0) {
            return head;
        } else {
            k %= num;
        }
        
        
        // Find break point p
        /*
           
            1 - 2 - 3 - 4 - 5
                    |       |            
                    p      tail
                    
            
            1 - 2 - 3 - NULL  4 - 5
                    |             |            
                    p            tail
            
            4 - 5 - 1 - 2 - 3 - NULL  
                |           |            
               tail         p  
                  
        */
        
        p = tempHead;
        for(int i= 0; i < (num - k) % num ; i++){
            p = p -> next;
        }
        
        tail -> next = head;
        tempHead -> next = p -> next;
        p -> next = nullptr;
            
        return tempHead -> next;
        
    }
};
