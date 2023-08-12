/*
    mergeTwoSorted function merges two sorted linked list recursively.
    With this method, we can merge two ajacent linked list until only one left.

*/


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

    ListNode* mergeTwoSorted(ListNode* p, ListNode* q) {
        if(p == NULL)
            return q;
        if(q == NULL)
            return p;

        if(p -> val < q -> val) {
            p -> next = mergeTwoSorted(p->next, q);
            return p;
        } 
        q -> next = mergeTwoSorted(p, q->next);
        return q;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.size() <= 0)
            return NULL;

        while (lists.size() > 1) {
            vector<ListNode*> temp;
            for(int i=0; i < lists.size(); i+= 2) {
                if( i + 1 < lists.size()) 
                    temp.push_back( mergeTwoSorted(lists[i], lists[i+1]) );
                else
                    temp.push_back( lists[i] );
            }
            lists = temp;
        }
        return lists[0];
    }
};