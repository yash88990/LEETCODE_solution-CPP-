class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Agar list empty hai ya sirf ek node hai, to wahi return karo
        if (!head || !head->next) return head;

        // Ek temporary dummy node create karte hain, jo head se pehle point karegi
        ListNode* temp = new ListNode(0, head);

        // Prev pointer dummy node pe set karo
        ListNode* prev = temp;

        // Current node traverse karne ke liye
        while (head) {
            // Agar current node aur uske next node ka value same hai
            if (head->next && head->val == head->next->val) {
                // Jab tak same values milti hain, aage badhte raho
                while (head->next && head->val == head->next->val) {
                    head = head->next; // Same value wale nodes skip karo
                }
                // Prev ka next ko next distinct node par set karo
                prev->next = head->next;
            } else {
                // Agar current node unique hai, prev ko aage badhao
                prev = prev->next;
            }
            // Head pointer ko aage badhao
            head = head->next;
        }

        // Dummy node ke next ko return karo jo nayi list ka head hai
        return temp->next;
    }
};
