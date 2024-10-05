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
    void reorderList(ListNode* head) {
        if(head == NULL)
        {
            return;
        }
        // find the middle of linked list [Problem 876]
        // in 1->2->3->4->5->6 find 4 
        ListNode* fast = head;
        ListNode* slow = head;

        //find the middle of list
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        // reverse the second part of the list [Problem 206]
        // convert 1->2->3->4->5->6 into 1->2->3->4 and 6->5->4

        ListNode* prev = NULL;
        ListNode* curr = slow;

        //reverse the second half
        while(curr != NULL){
            ListNode* tmp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = tmp;
        }

        // merge two sorted linked lists [Problem 21]
        // merge 1->2->3->4 and 6->5->4 into 1->6->2->5->3->4
        ListNode* newHead = head;
        ListNode* tail = prev;
        ListNode* tmp = new ListNode(0);
        while(tail->next != NULL)
        {
            tmp = newHead->next;
            newHead->next = tail;
            newHead = tmp;

            tmp = tail->next;
            tail->next = newHead;
            tail = tmp;
        }
    }
};