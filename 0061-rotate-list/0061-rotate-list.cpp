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
        if(!head || !head->next || k == 0 ) return head;
        //linked list ka length 
        ListNode* curr = head ;
        int length = 1;

        while(curr->next){
            curr = curr->next;
            length++;
        }
        k = k % length ;
        if(k ==0 ) return head;
        curr->next = head ;
        int stepToNewHead = length - k ;
        ListNode* newTail = head;
        for(int i = 1 ; i < stepToNewHead ; i++){
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;
        newTail->next = NULL;
        return newHead;
    }
};