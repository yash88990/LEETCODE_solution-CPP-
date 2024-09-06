class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // Convert the nums array to a set for fast lookup
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Dummy node to handle edge cases like removing the head
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        ListNode* current = head;
        
        while (current != nullptr) {
            if (numSet.count(current->val)) {
                // If current node's value is in the set, remove the node
                prev->next = current->next;
            } else {
                // Otherwise, move prev forward
                prev = current;
            }
            // Move to the next node in the list
            current = current->next;
        }
        
        // Return the modified list starting from dummy->next
        return dummy->next;
    }
};
