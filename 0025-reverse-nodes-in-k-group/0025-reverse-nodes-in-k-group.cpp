class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;
        
        ListNode* curr = head;
        int count = 0;
        
        // Find the head of the next group
        while (count < k && curr) {
            curr = curr->next;
            count++;
        }
        
        // If the remaining nodes are less than k, no reversal is needed
        if (count < k) return head;
        
        // Reverse the first group of k nodes
        ListNode* reversedHead = reverseKNodes(head, k);
        
        // Recursively reverse subsequent groups
        head->next = reverseKGroup(curr, k);
        
        return reversedHead;
    }
    
    ListNode* reverseKNodes(ListNode* head, int k) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = nullptr;
        
        while (k--) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
};
