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
        if(head == null){
            return null;
        }

        ListNode current = head;
        Stack<ListNode> stack = new Stack<>();

        // Use a stack to keep track of nodes to be preserved
        while(current != null){
            while(!stack.isEmpty() && stack.peek().val < current.val){
                stack.pop();
            }

            stack.push(current);
            current = current.next;
        }

        ListNode temp = null;
        // Build the new linked list by popping values from the stack
        while(!stack.isEmpty()){
            current = stack.pop();
            current.next = temp;
            temp = current;
        }

        return current;
    }
}