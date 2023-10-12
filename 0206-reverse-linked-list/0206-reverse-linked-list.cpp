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
    ListNode* reverseList(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        // Previous ptr
        ListNode* prev = NULL;
        // Current ptr
        ListNode* curr = head;
        //next ptr
        ListNode* nex;

        //continue curr till it is not null
        while(curr)
        {
            nex = curr->next;
            curr->next = prev;

            prev = curr;
            curr = nex;
        }
        head = prev;
        return head;
    }
};