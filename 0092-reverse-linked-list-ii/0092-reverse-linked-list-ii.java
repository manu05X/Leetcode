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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        // If there is only one node or no need to reverse, return the original list.
        if (head.next == null || left == right) {
            return head;
        }
      
        // Dummy node to simplify the handling of the head node.
        ListNode dummyNode = new ListNode(0, head);
      
        // Pointer to track the node before the reversal section.
        ListNode nodeBeforeReverse = dummyNode;
        for (int i = 0; i < left - 1; ++i) {
            nodeBeforeReverse = nodeBeforeReverse.next;
        }
      
        // 'firstReversed' will become the last node after the reversal.
        ListNode firstReversed = nodeBeforeReverse.next;
        // 'current' is used to track the current node being processed.
        ListNode current = firstReversed;
        ListNode prev = null;
      
        // Perform the actual reversal between 'left' and 'right'.
        for (int i = 0; i < right - left + 1; ++i) {
            ListNode nextTemp = current.next;
            current.next = prev;
            prev = current;
            current = nextTemp;
        }
      
        // Reconnect the reversed section back to the list.
        nodeBeforeReverse.next = prev;      // Connect with node before reversed part.
        firstReversed.next = current;       // Connect the last reversed node to the remainder of the list.
      
        // Return the new head of the list.
        return dummyNode.next;
    }
}