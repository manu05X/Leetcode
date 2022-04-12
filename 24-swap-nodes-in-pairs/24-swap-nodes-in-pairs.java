/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 
 ALGORITHM
Step 1. Init temp holder Use nextPair to store next pair's position
Step 2. Swap, make second point to first, prev point to second, and first point to nextPair
Step 3. Update: Update prev and current pointer to corresponding temp holde
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