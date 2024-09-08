class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // Step 1: Count the total number of nodes in the linked list
        int totalNodes = 0;
        ListNode* current = head;
        while (current) {
            totalNodes++;
            current = current->next;
        }
        
        // Step 2: Calculate the size of each part
        int partSize = totalNodes / k;
        int remainder = totalNodes % k; // This many parts will have one extra node
        
        // Step 3: Split the list into parts
        vector<ListNode*> result(k, nullptr);
        current = head;
        
        for (int i = 0; i < k; ++i) {
            if (!current) break;  // If no more nodes left, the remaining parts will be null
            
            result[i] = current;  // Start the current part
            int currentPartSize = partSize + (i < remainder ? 1 : 0);  // Add an extra node to the first 'remainder' parts
            
            // Move current pointer to the end of the current part
            for (int j = 1; j < currentPartSize; ++j) {
                if (current) {
                    current = current->next;
                }
            }
            
            // Break the link to form a separate part
            if (current) {
                ListNode* nextPart = current->next;
                current->next = nullptr;  // Disconnect the current part from the rest of the list
                current = nextPart;       // Move to the next part
            }
        }
        
        return result;
    }
};
