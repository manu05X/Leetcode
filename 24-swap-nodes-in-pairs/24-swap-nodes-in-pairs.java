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
    public ListNode swapPairs(ListNode head) {
        ListNode curr = head;
        
        while(curr != null && curr.next != null){
            // temp store the curr val
            int temp = curr.val;
            //update curr val with next node val
            curr.val = curr.next.val;
            //restore the curr next val with temp val 
            curr.next.val = temp;
            
            // move the curr to 2 node ahead 
            curr = curr.next.next;
        }
        return head;
    }
}