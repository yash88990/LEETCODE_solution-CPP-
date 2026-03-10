/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        // Base case: if list is empty or has one node
        if (head == null || head.next == null) {
            return head;
        }

        ListNode curr = head;
        ListNode prev = null;

        while (curr != null) {
            // Save the next node before overwriting curr.next
            ListNode temp = curr.next;
            
            // Reverse the link
            curr.next = prev;
            
            // Move pointers forward
            prev = curr;
            curr = temp;
        }

        // prev is now the new head of the reversed list
        return prev;
    }
}