class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Count total nodes
        int count = 0;
        ListNode* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }

        // Special case: if the node to delete is the head
        if (n == count) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Step 2: Find the (count - n)th node (node just before the one to delete)
        int steps = count - n;
        temp = head;
        for (int i = 1; i < steps; ++i) {
            temp = temp->next;
        }

        // Step 3: Delete the node
        ListNode* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        return head;
    }
};
