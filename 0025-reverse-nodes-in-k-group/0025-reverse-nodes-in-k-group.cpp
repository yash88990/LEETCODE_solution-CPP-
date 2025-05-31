class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node to ease edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroupEnd = dummy;
        ListNode* curr = head;

        while (true) {
            // Check if there are at least k nodes left to reverse
            ListNode* check = curr;
            for (int i = 0; i < k; ++i) {
                if (!check) return dummy->next;  // Not enough nodes
                check = check->next;
            }

            // Reverse k nodes
            ListNode* groupStart = curr;
            ListNode* prev = NULL;
            ListNode* next = NULL;

            for (int i = 0; i < k; ++i) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect previous part to reversed group
            prevGroupEnd->next = prev;
            groupStart->next = curr;
            prevGroupEnd = groupStart;
        }

        return dummy->next;
    }
};
