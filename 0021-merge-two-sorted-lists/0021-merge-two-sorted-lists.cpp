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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(); // Dummy node to start the merged list
        ListNode* tail = dummy; // Pointer to the last node of the merged list
        
        // Iterate through both lists until one of them reaches the end
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1; // Append list1 node to merged list
                list1 = list1->next; // Move to the next node in list1
            } else {
                tail->next = list2; // Append list2 node to merged list
                list2 = list2->next; // Move to the next node in list2
            }
            tail = tail->next; // Move tail pointer to the newly added node
        }
        
        // Append the remaining nodes from list1 or list2 (if any)
        if (list1) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        
        ListNode* mergedList = dummy->next; // Head of the merged list
        delete dummy; // Free dummy node
        return mergedList;
    }
};
