/*

ANSWER: This is a very tricky problem.

 |----C----┬-------------┐
           |             |
           └------L------┘

First of all, it is quite stragith forward to apply "fast/slow pointer" algorithm to detect existence of a circle. See Problems 141.

Now Let's discuss how to find the start node of the circle.


State 1: When the slow pointer is about to enter the circle:

          slow     fast
           |        |
 |----C----┬----C---|----┐
           |             |
           └----(L-C)----┘

State 2: slow pointer meets faster pointer:

 |----C----┬----(L-C)----┐
           C             |
           └---|---------┘
               |
           slow,fast
           
It is quite easy to find that when fast pointer meets slow pointer, they are (L-C) away from the enter pointer of the circle, because that:

- fast pointer catches 1 nodes per step
- In State1, fast pointer was C nodes ahead of slow pointer, which means faster pointer needs L-C steps to catch up the slow pointer.

State 3: Solving the problem. 

 |----C----┬----(L-C)----┐
 |         C             |
slow       └---|---------┘
               |
              fast
Now, reset slow pointer to the head, and move slow and fast 1 nodes each step, they will finally meet at entry node of the circle.

*/



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
    ListNode *detectCycle(ListNode *head) {
        
        if(!head || !head->next || !(head -> next -> next))
            return nullptr;
        
        ListNode *fast=head, *slow=head;       
        do {
            fast = fast -> next -> next;
            slow = slow -> next;               
        } while(fast -> next && (fast -> next -> next) && fast != slow);
        
        if( fast != slow){
            return nullptr;
        }
        
        slow = head;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }
        return fast;
    }
};
