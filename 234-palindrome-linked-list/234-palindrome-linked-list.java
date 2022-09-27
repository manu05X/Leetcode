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
    public boolean isPalindrome(ListNode head) {
        ListNode fast = head;
        ListNode slow = head;
        ListNode prev, temp;
        
        // finding the middle of List
        while(fast.next != null && fast.next.next != null)
        {
            slow = slow.next;
            fast = fast.next.next;
        }
        // reverse half of the list
        prev = slow; slow = slow.next; prev.next = null;
        
        while(slow != null)
        {
            temp = slow.next;
            slow.next = prev;
            prev = slow;
            slow = temp;
        }
        // make fast point at start and slow at end i.e prev and iterate
        fast = head; slow = prev;
        
        while(slow.next != null)
        {
            if(fast.val != slow.val)
            {
                return false;
            }
            else
            {
                slow = slow.next;
                fast = fast.next;
            }
        }
        
        return true;
    }
}