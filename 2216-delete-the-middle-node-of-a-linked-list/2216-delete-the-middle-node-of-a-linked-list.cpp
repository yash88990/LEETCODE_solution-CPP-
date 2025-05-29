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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL)return NULL;
        int count = 0 ;
        ListNode* temp = head;
        while(temp){
            count++;
            temp= temp->next;
            
        }
        int  mid = count / 2 ;
        temp = head;
        
        for(int i = 0 ; i < mid - 1; i++){
            temp = temp->next;
        }
        ListNode* nodetodelete = temp->next;
        temp->next = temp->next->next;
        delete nodetodelete;

        return head;
        

    }
};
