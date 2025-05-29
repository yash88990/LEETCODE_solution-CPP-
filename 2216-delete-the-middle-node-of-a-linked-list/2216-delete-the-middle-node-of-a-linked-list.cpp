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
// class Solution {
// public:
//     ListNode* deleteMiddle(ListNode* head) {
//         int count = 0 ;
//         while(head){
//             head= head->next;
//             count++;
//         }
//         int  mid = 0;
//         if(count % 2 == 0){
//             mid = count / 2;

//         }else{
//             mid = count / 2 + 1 ;
//         }
//         while(mid < count){

//         }
        

//     }
// };

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: only one node
        if (!head || !head->next) return nullptr;

        // Step 1: Count the total number of nodes
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }

        // Step 2: Find the index just before the middle
        int mid = len / 2;

        // Step 3: Traverse to the node just before the middle
        temp = head;
        for (int i = 0; i < mid - 1; i++) {
            temp = temp->next;
        }

        // Step 4: Delete the middle node
        ListNode* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;

        return head;
    }
};
