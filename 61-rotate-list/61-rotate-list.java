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
        if(head == null || head.next == null || k == 0)
        {
            return head;
        }
        //calculating length
        ListNode curr = head;
        int len = 1;
        while(curr.next != null)
        {
            len++;
            curr = curr.next;
        }
        //link last node to first node
        curr.next = head;
        //when k is more than length of list
        k = k%len;
        
        int end = len-k;
        while(end != 0)
        {
            end--;
            curr = curr.next;
        }
        //breaking last node link and pointing to NULL
        head = curr.next;
        curr.next = null;
        
        return head;
    }
}