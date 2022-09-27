/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null)
            return null;
        
        ListNode fast = head;
        ListNode slow = head;
        
        ListNode start = head;
        while(fast.next != null && fast.next.next != null)
        {
            fast = fast.next.next;
            slow = slow.next;
            
            if(fast == slow)
            {
                while(start != slow)
                {
                    slow = slow.next;
                    start = start.next;
                }
                return start;
            }
        }
        
        return null;
    }
}