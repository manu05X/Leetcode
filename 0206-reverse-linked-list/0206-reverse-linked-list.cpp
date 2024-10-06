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

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = temp;
        }

        head = prev;
        return head;
    }
};


// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ios_base::sync_with_stdio(false);         
//         cin.tie(NULL);

//         if(head == NULL || head->next == NULL){
//             return head;
//         }

//         ListNode* p = reverseList(head->next);
//         head->next->next = head;
//         head->next = NULL;

//         return p;
//     }
// };