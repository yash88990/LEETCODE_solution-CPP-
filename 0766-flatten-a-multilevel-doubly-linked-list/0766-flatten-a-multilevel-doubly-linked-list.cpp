class Solution {
public:
    // Helper function that flattens the list and returns the tail node of the flattened list
    Node* flattenGetTail(Node* head) {
        Node* curr = head;
        Node* tail = head;

        while (curr) {
            Node* nextNode = curr->next;

            // If current node has a child, flatten the child list first
            if (curr->child) {
                Node* childHead = curr->child;
                Node* childTail = flattenGetTail(childHead);

                // Insert the child list between curr and nextNode
                curr->next = childHead;
                childHead->prev = curr;

                // Connect childTail to nextNode if it exists
                if (nextNode) {
                    childTail->next = nextNode;
                    nextNode->prev = childTail;
                }

                // Child pointer should be set to nullptr after flattening
                curr->child = nullptr;

                // Update tail to childTail because the list got extended
                tail = childTail;
                curr = childTail;
            } else {
                tail = curr; // Update tail as we traverse
            }

            curr = curr->next;
        }

        return tail;
    }

    Node* flatten(Node* head) {
        if (!head) return head;

        flattenGetTail(head);
        return head;
    }
};
