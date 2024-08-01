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
    public ListNode reverseKGroup(ListNode head, int k) {
        int count = 0;
        ListNode current = head;
        while(count != k && current != null)
        {
            count++;
            current = current.next;
        }
        if(count == k)
        {
            current = reverseKGroup(current,k);
            while(count > 0)
            {
                count--;
                ListNode temp = head.next;
                head.next = current;
                current = head;
                head = temp;
            }
            head = current;
            
        }
        return head;
    }
}