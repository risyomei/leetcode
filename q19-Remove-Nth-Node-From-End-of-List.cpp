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


/*
Answer:

when n == 2:

loop start:
  1 - 2 - 3 - 4 - 5
  |       |
  p       e
  
loop end:
  1 - 2 - 3 - 4 - 5
          |       |
          p       e
          
then:
p is the target to be deleted.
            
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *temphead =  new ListNode(0, head);
        ListNode *p = temphead;
        ListNode *e = temphead->next;       
       
        
        for(int i=0; i< n;i++){
            
            if(e!= nullptr){
                e = e -> next;    
            }
            else{
                // not enough length 
                return new ListNode(-1, head);
            }
        }
        
        while(e!=nullptr){
            e = e -> next;
            p = p -> next; 
        }
        
        ListNode *t = p -> next;
        p -> next = t -> next;
        delete t;
        return temphead -> next;
    }
};
