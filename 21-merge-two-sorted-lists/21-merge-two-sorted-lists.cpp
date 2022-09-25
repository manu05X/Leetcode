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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode();
        ListNode* head;
        head = l3;
        
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2-> val)
            {
                ListNode* temp = new ListNode(l1->val);
                l3->next = temp;
                l3 = l3->next;
                l1 = l1->next;
            }
            else
            {
                ListNode* temp = new ListNode(l2->val);
                l3->next = temp;
                l3 = l3->next;
                l2 = l2->next;
            }
        }
        if(l1 == NULL)
        {
            l3->next = l2;
        }
        else
        {
            l3->next = l1;
        }
        
        return head->next;
    }
};