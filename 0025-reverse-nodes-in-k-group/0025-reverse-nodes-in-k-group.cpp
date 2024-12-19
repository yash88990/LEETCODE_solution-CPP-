class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node to handle edge cases easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy, *next = dummy, *prev = dummy;
        int length = 0;

        // Find the length of the linked list
        while (curr->next) {
            curr = curr->next;
            length++;
        }

        // Reverse in groups of k
        while (length >= k) {
            curr = prev->next;
            next = curr->next;

            // Reverse k nodes
            for (int i = 1; i < k; ++i) {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }

            // Move the prev pointer to the end of the reversed group
            prev = curr;
            length -= k;
        }

        return dummy->next;
    }
};
