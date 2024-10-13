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
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists == null || lists.length == 0) {
            return null;
        }
        
        // Use a priority queue (min-heap) to store the nodes
        PriorityQueue<ListNode> queue = new PriorityQueue<ListNode>((a, b) -> a.val - b.val);
        
        // Add the first node of each list to the priority queue
        for (ListNode node : lists) {
            if (node != null) {
                queue.add(node);
            }
        }

        // Dummy node to start the merged list
        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;
        
        // Continue until the priority queue is empty
        while (!queue.isEmpty()) {
            // Get the node with the smallest value
            tail.next = queue.poll();
            tail = tail.next;
            
            // If there's a next node in the current list, add it to the queue
            if (tail.next != null) {
                queue.add(tail.next);
            }
        }
        
        // Return the merged list, which starts at dummy.next
        return dummy.next;
    }
}
