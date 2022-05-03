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

Reverse the half of the link list, and then compare it with the rest.

Step0:
H: 1 - 2 - 3 - 3 - 2 - 1

Step1:
H: 1 
R: 2 - 3 - 3  - 2 - 1

Step2:
H: 2 - 1
R: 3 - 3  - 2 - 1

Step3:
H: 3 - 2 - 1
R: 3  - 2 - 1

Step4:
Compare
*/


class Solution {
public:
    bool isPalindrome(ListNode* aaahead) {
        int count = 0;
        ListNode* temp = aaahead;
        while(temp){
            count ++;
            temp = temp -> next;
        }

        ListNode* head = new ListNode(-1,aaahead);
        ListNode* tail = new ListNode(-1,NULL);

        int i=0;
        for(; i<count/2; i++) {
            ListNode* tn = tail -> next;
            ListNode* hn = head -> next;

            head -> next = hn -> next;
            tail -> next = hn;
            hn -> next = tn;
        }

        // Skip if count is odds
        //  Step0: H: 1 - 2 - 3(skip this) - 2 - 1
        //  Step1: H: 3(skip this) - 2 - 1
        //         R: 2 - 1

        if(count%2!=0) {
            head = head -> next;
            i++;
        }

        head = head -> next;
        tail = tail -> next;

        for( ; i<count; i++) {
            if(head -> val != tail -> val )
                return false;
            head = head -> next;
            tail = tail -> next;
        }
        return true;
    }
};
