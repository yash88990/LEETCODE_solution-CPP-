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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head->next)return NULL;
        int size=0;
        ListNode* curr=head;
        while(curr){
            curr=curr->next;
            size++;
        }
        int pos = size - n;
        if(pos == 0){
            ListNode* temp = head;
            head = head->next;
            temp->next=NULL;
            delete temp;
            return head;

        }
        int cnt = 0;
        curr=head;
        while(curr && cnt < pos - 1 ){
            cnt++;
            curr=curr->next;
        }
        ListNode* temp = curr->next;
        curr->next = temp->next;
        temp->next=NULL;
        delete temp;
        return head;
    }
};