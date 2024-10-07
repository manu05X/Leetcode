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
        if(head == null){
            return head;
        }
        /*  c  l     r
            1->2->3->4->5
        */
        ListNode curr = head;
        ListNode prev = null;
        while(left > 1){
            prev = curr;
            curr = curr.next;
            left--;
            right--;
        }
         /* l  c  r    
            1->2->3->4->5
            p
        */

        ListNode start = prev; // storing the prev as start next is the begning of left pointer for reversing the linked list
        ListNode end = curr; // curr would become the tail of reverse group;
        /*  l     r    
            1->2->3->4->5
            st end
        */

        while(right > 0){
            ListNode tmp = curr.next;
            curr.next = prev;
            
            prev = curr;
            curr = tmp;

            right--;
        }
        /*  l  e  r  p  c
            1<-2<-3<-4  5
            s

                ________
            l  |  r  p  |
            1  2<-3<-4  5
            s  e        c
        */

        if(start != null){
            start.next = prev;
        }
        /*
                ________
            l  |  r  p  |
            1  2<-3<-4  5
            s  e        c
         */
        else{
            head = prev;
        }

        /*
                ________
            s  |  r  p  |
            1  2<-3<-4  5
            |  e     |  c
            ----------

        */
        end.next = curr;

        /*   
            s        p  
            1->4->3->2->5
               e        c
         */
        return head;
    }
}

/*
1->2->3->4->5

 */





/*

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
*/