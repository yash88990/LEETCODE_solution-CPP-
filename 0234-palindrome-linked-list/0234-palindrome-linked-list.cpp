class Solution {
public:
    // Helper function to reverse a linked list
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* secondHalf = reverseList(slow);

        // Step 3: Compare both halves
        ListNode* firstHalf = head;
        ListNode* temp = secondHalf;
        while (temp) {
            if (firstHalf->val != temp->val) return false;
            firstHalf = firstHalf->next;
            temp = temp->next;
        }

        // Step 4 (optional): Restore list
        // reverseList(secondHalf); // Uncomment if original list structure is needed

        return true;
    }
};
