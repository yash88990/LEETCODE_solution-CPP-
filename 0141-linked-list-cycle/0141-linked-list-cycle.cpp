class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Agar list empty hai ya sirf ek node hai, to cycle nahi ho sakti
        if (!head || !head->next) return false;

        // Two pointers: slow (tortoise) and fast (hare)
        ListNode* slow = head; // Slow pointer ek step aage badega
        ListNode* fast = head; // Fast pointer do steps aage badega

        // Jab tak fast pointer aur uska next NULL nahi ho jata
        while (fast && fast->next) {
            slow = slow->next;           // Slow ek step move karega
            fast = fast->next->next;     // Fast do steps move karega

            // Agar slow aur fast meet karte hain, cycle detect ho gayi
            if (slow == fast) return true;
        }

        // Agar fast pointer null tak pahunch gaya, to cycle nahi hai
        return false;
    }
};
