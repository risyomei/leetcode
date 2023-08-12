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

 /* Solution 1 with loop */
/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* p1, ListNode* p2) {

        if (p1 == NULL)
            return p2;
        if (p2 == NULL)
            return p1;
        
        ListNode* answer = new ListNode(0);
        ListNode* ans = answer;

        while (p1 != NULL && p2 != NULL) {
            if(p1 -> val < p2 -> val) {
                ans -> next = p1;
                p1 = p1 -> next;
            } else {
                ans -> next = p2;
                p2 = p2 -> next;
            }
            ans = ans -> next;            
        }

        while (p1 != NULL) {
            ans -> next = p1;
            ans = ans -> next;
            p1 = p1 -> next;
        }

        while (p2 != NULL) {
            ans -> next = p2;
            ans = ans -> next;
            p2 = p2 -> next;
        }
        return answer -> next;
    }
};
*/

/* Solution 2 with recursive */
class Solution {
    ListNode* ans;
public:
    void findSmaller(ListNode* p1, ListNode* p2) {
        if(p1 == NULL && p2 == NULL) {
            ans -> next = NULL;
            return;
        }
        if(p1 == NULL) {
            ans -> next = p2;
            return;
        }
        if(p2 == NULL) {
            ans -> next = p1;
            return;
        }
        // P1, P2 都不NULL
        if(p1 -> val < p2 -> val) {
            ans -> next = p1;
            ans = ans -> next;
            cout << p1 -> val << endl;
            findSmaller(p1 -> next, p2);
        } else {
            ans -> next = p2;
            ans = ans -> next;
            cout << p2 -> val << endl;
            findSmaller(p1, p2 -> next);
        }
    }

    ListNode* mergeTwoLists(ListNode* p1, ListNode* p2) {
        
        ListNode* answer = new ListNode(0);
        ans = answer;
        findSmaller(p1, p2);
        return answer -> next;
    }
};
