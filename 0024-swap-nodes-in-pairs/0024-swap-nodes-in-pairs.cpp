

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Create a dummy node to serve as the new head of the list
        ListNode dummy(0);
        dummy.next = head;
        
        // Pointer to the previous node before the pair being swapped
        ListNode* prev = &dummy;
        
        // Iterate through the list until we have at least two nodes remaining
        while (head && head->next) {
            // Nodes to be swapped
            ListNode* first = head;
            ListNode* second = head->next;
            
            // Swapping the nodes
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            // Move pointers for the next pair
            prev = first;
            head = first->next;
        }
        
        return dummy.next;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
