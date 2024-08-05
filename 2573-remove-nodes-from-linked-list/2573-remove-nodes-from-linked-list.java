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
    public ListNode removeNodes(ListNode head) {
         // Initialize an array to store the node values
        List<Integer> nodeValues = new ArrayList<>();
      
        // Iterate through linked list to collect values
        while (head != null) {
            nodeValues.add(head.val);
            head = head.next;
        }
      
        // Use a stack to keep track of nodes to be preserved
        Deque<Integer> stack = new ArrayDeque<>();
        for (int value : nodeValues) {
            // Remove all elements from stack that are smaller than current value
            while (!stack.isEmpty() && stack.peek() < value) {
                stack.pop();
            }
            // Push the current value onto the stack
            stack.push(value);
        }
      
        // Create a dummy node to build the resulting linked list
        ListNode dummy = new ListNode(0);
        ListNode current = dummy;
      
        // Build the new linked list by popping values from the stack
        while (!stack.isEmpty()) {
            // Since stack is LIFO, use stack.pollLast() to maintain original order of remaining nodes
            current.next = new ListNode(stack.pollLast());
            current = current.next;
        }
      
        // Return the next node of dummy since first node is a placeholder
        return dummy.next;
    }
}