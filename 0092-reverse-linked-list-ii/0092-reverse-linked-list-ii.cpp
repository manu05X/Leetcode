/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next; 
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Empty list
        if(head == NULL)
            return NULL;
        // Move the two pointers until they reach the proper starting point
        // in the list.
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(left > 1)
        {
            prev = curr;
            curr = curr->next;
            left--;
            right--;
        }
        // The two pointers that will fix the final connections.
        ListNode* st = prev;
        ListNode* end = curr;
        // Iteratively reverse the nodes until n becomes 0.
        ListNode* tmp = NULL;
        
        while(right > 0)
        {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            right--;
        }
        // Adjust the final connections as explained in the algorithm
        if(st != NULL)
            st->next = prev;
        else
            head = prev;
        
        end->next = curr;
        return head;
    }
};