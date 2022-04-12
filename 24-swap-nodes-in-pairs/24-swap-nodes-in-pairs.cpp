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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;
        
        while(curr != NULL && curr->next != NULL){
            // temp store the curr val
            int temp = curr->val;
            //update curr val with next node val
            curr->val = curr->next->val;
            //restore the curr next val with temp val 
            curr->next->val = temp;
            
            // move the curr to 2 node ahead 
            curr = curr->next->next;
        }
        return head;
    }
};