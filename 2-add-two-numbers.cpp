link list
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int overflow = 0;
        
        ListNode* head = new ListNode(0);
        ListNode* current = head;
        
        while( l1 != NULL || l2 != NULL || overflow != 0 ){
            
            int sum = overflow;
        
            if (l1 != NULL) {
                sum += l1 -> val;
                l1 = l1 -> next;
            }
            
            if (l2 != NULL) {
                sum += l2 -> val;
                l2 = l2 -> next;                
            }
            
            overflow = sum / 10;
            sum = sum % 10;
            
            ListNode* temp = new ListNode(sum);
            current -> next = temp;
            current = temp;
        }
        return head -> next;
    }
};
