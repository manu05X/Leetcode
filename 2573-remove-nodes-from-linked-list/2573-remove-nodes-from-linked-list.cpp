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
    ListNode* removeNodes(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(head == NULL) return NULL;

        ListNode* curr = head;
        stack<ListNode*> st;

        // Use a stack to keep track of nodes to be preserved
        while(curr != NULL)
        {
            while(!st.empty() && st.top()->val < curr->val){
                st.pop();
            }

            st.push(curr);
            curr = curr->next;
        }

        ListNode* temp = NULL;
        // Build the new linked list by popping values from the stack
        while(!st.empty()){
            curr = st.top();
            st.pop();
            curr->next = temp;
            temp = curr;
        }

        return curr;

    }
};


