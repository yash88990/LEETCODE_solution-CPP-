class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; ++i)
            fast = fast->next;

        // Move both fast and slow pointers until fast reaches the end
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the nth node from the end
        ListNode *to_remove = slow->next;
        slow->next = slow->next->next;
        delete to_remove;

        return dummy.next;
    }
};
