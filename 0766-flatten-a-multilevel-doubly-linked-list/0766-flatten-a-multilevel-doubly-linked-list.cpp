/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {

public:
    Node* solve(Node* head){
        Node* curr = head , *tail = head;
        while(curr){
            Node* nextNode = curr->next;
            //priority 1 :- check for child (top to bottom)
            if(curr->child){
                Node* childHead = curr->child;
                Node* childTail = solve(childHead);

                curr->next = childHead;
                childHead->prev = curr;

                if(nextNode){
                    childTail->next= nextNode;
                    nextNode->prev = childTail;
                }
                curr->child = NULL;

                tail = childTail;
                curr = childTail;


            }else{
                tail = curr;

            }
            curr = curr->next;
            
        }
        return tail;
    }
    Node* flatten(Node* head) {
        if(!head)return head;
        solve(head);
        return head;
        
    }
};