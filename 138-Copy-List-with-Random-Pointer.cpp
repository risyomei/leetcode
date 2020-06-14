/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        
        map<Node*, int>  src_mapping;
        map<int, Node*>  dst_mapping;

        // for old traverse
        Node* p = head;        

        // for new link list
        Node* newHead = new Node(-1);
        Node* q = newHead;
                        
        // build link list with vale
        int i = 0;
        while(p!=nullptr){
                        
            // Added a new node with value/next.
            Node *q_old = q;
            q = new Node(p->val);
            q_old -> next = q;
            q -> next = nullptr;
            
            // update index
            src_mapping[p] = i;
            dst_mapping[i] = q;
            
            // next node;
            p = p->next;
            i ++;
        
        }
        
        p=head;
        q=newHead->next;
        
        while(p!=nullptr){         
            if(p->random == nullptr) {
                q -> random = nullptr;
            } else {
                q -> random = dst_mapping[src_mapping[p->random]];        
            }
            p=p->next;
            q=q->next;
            
        }
        
        return newHead->next;
    }
};
