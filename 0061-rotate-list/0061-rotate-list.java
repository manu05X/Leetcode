/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || head.next == null || k == 0) {
            return head;
        }

        // Calculate the length of the list
        ListNode curr = head;
        int len = 1;
        while (curr.next != null) {
            len++;
            curr = curr.next;
        }

        // Link the last node to the first node to make it a circular list
        curr.next = head;

        // When k is more than the length of the list
        k = k % len;

        // Find the new tail, which will be (len - k) nodes away from the current node
        int newTailIndex = len - k;
        while (newTailIndex != 0) {
            newTailIndex--;
            curr = curr.next;
        }

        // The new head is the next node of the new tail
        head = curr.next;
        // Break the circular link
        curr.next = null;

        return head;
    }
}