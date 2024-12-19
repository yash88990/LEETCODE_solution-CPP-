class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Agar list empty hai ya sirf ek node hai, to wahi list return karo
        if (!head || !head->next) return head;

        ListNode* prev = nullptr; // Pehle pointer null pe set karte hain
        ListNode* curr = head;    // Current pointer head pe set karte hain

        // Jab tak current null nahi ho jata, list ko reverse karte hain
        while (curr) {
            ListNode* nextNode = curr->next; // Next node ko store karte hain
            curr->next = prev;              // Current ka next pichle node pe point kare
            prev = curr;                    // Prev pointer ko current node pe le aao
            curr = nextNode;                // Current pointer ko next node pe le aao
        }

        // Last me prev pointer nayi head ban jayegi
        return prev;
    }
};
