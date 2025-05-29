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
ListNode* reverseList(ListNode* head) {
        if(head == NULL || head ->next == NULL)return head;
        ListNode* curr  = head ,* prev = NULL;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)return true;
        //find middle 
        ListNode* slow = head ;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse half
        ListNode* secondhalf = reverseList(slow);
        //comapre 
        ListNode* firsthalf = head;
        ListNode *temp = secondhalf;
        while(temp){
            if(firsthalf->val != temp->val)return false;
            firsthalf = firsthalf->next;
            temp = temp->next;
        }
        return true;
        

    }
};