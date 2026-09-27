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
    void reorderList(ListNode* head) {
        //find middle
        ListNode* slow = head , *fast=head;
        while(fast && fast->next){
            slow = slow->next;
            fast= fast->next->next;
        }
        //split into two halves
        ListNode* secondhalf = slow->next;
        slow->next = NULL;
        //reverse second half 
        ListNode* prev = NULL;
        while(secondhalf){
            ListNode* temp = secondhalf->next;
            secondhalf->next=prev;
            prev = secondhalf;
            secondhalf = temp;
        }
        //merge 
        ListNode* firsthalf = head ;
        secondhalf = prev ;
        while(secondhalf){
            ListNode* temp = secondhalf->next;
            secondhalf->next=firsthalf->next;
            firsthalf->next=secondhalf;

            firsthalf=secondhalf->next;
            secondhalf=temp;
            
        }
   
    }
};