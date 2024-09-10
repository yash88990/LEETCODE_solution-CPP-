
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // If the list is empty or contains only one node, return it as is
        if (!head || !head->next) {
            return head;
        }

        ListNode* current = head;

        // Traverse the list until the second last node
        while (current && current->next) {
            // Get the value of the current node and the next node
            int currentVal = current->val;
            int nextVal = current->next->val;

            // Calculate the GCD of current and next node values
            int gcdValue = __gcd(currentVal, nextVal);  // Use built-in gcd function

            // Create a new node with the GCD value
            ListNode* gcdNode = new ListNode(gcdValue);

            // Insert this GCD node between current and next
            gcdNode->next = current->next;
            current->next = gcdNode;

            // Move to the node after the inserted GCD node
            current = gcdNode->next;
        }

        return head;
    }
};
