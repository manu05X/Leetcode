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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ios_base::sync_with_stdio(false);         
        cin.tie(NULL);
        
        ListNode* temp = new ListNode(); // Create a new node and set its next to the head
        temp->next = head;
        ListNode* slow = temp; // Initialize the slow pointer to the temp node
        ListNode* fast = temp; // Initialize the fast pointer to the temp node

        // Move the fast pointer n nodes ahead
        while (n--) {
            fast = fast->next;
        }

        // Move both pointers until the fast pointer reaches the end
        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the target node by adjusting the next pointers
        slow->next = slow->next->next;

        return temp->next; // Return the head of the modified linked list
    }
};