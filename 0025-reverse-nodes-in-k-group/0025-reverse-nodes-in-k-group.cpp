class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check if we have at least k nodes to reverse
        ListNode* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head; // Not enough nodes, return head as-is
            temp = temp->next;
        }

        // Step 2: Reverse k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        int count = 0;

        while (curr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 3: head now becomes the end of the group,
        // connect it with the result of next recursive call
        head->next = reverseKGroup(curr, k);

        // prev is new head of the reversed group
        return prev;
    }
};
