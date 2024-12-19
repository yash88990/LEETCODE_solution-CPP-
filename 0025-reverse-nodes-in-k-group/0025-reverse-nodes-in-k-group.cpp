class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Agar list empty hai ya k = 1 hai, to reversal ki zarurat nahi hai
        if (!head || k == 1) return head;

        // Temp node create karte hain jo start se pehle attach hoti hai
        ListNode* temp = new ListNode(0); 
        temp->next = head; // Temp node ka next list ke head ko point karega

        // Pointers initialize karte hain
        ListNode* curr = temp, *next = temp, *prev = temp;
        int length = 0; // List ki total length calculate karne ke liye

        // Poore list ka size count karte hain
        while (curr->next) {
            curr = curr->next; // Curr pointer ko aage move karte raho
            length++;          // Ek-ek node count karo
        }

        // Jab tak k nodes ka group reverse karna possible ho
        while (length >= k) {
            curr = prev->next; // Current group ka start node
            next = curr->next; // Current group ka second node

            // Group ke k nodes ko reverse karo
            for (int i = 1; i < k; ++i) {
                curr->next = next->next; // Current node ka next update karo
                next->next = prev->next; // Next node ko reversed group ke start pe add karo
                prev->next = next;       // Previous group ko naye reversed node se connect karo
                next = curr->next;       // Next pointer ko aage badhao
            }

            prev = curr;       // Prev pointer ko reversed group ke end pe move karo
            length -= k;       // Remaining length ko k se kam karo
        }

        // Modified list ka head return karo
        return temp->next; 
    }
};
