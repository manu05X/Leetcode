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
         // Create a dummy node to anchor the modified list and simplify edge cases
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;

        // Use 'previousNode' to keep track of the last node of the previous pair
        ListNode* prev = dummyNode;

        // 'currentNode' will be used to iterate through the original list
        ListNode* curr = head;

        // Proceed with swapping pairs while there are at least two nodes left to process
        while (curr && curr->next) {
            // Identify the node to be swapped with the current node
            ListNode* temp = curr->next;

            // Swap the pair by reassigning pointers
            curr->next = temp->next;
            temp->next = curr;
            prev->next = temp;

            // Move 'previousNode' pointer forward to the current node after swap
            prev = curr;

            // Move 'currentNode' pointer forward to the next pair
            curr = curr->next;
        }

        // The 'dummyNode.next' now points to the head of the modified list
        ListNode* swappedHead = dummyNode->next;

        // Clean up memory by deleting the dummy node
        delete dummyNode;

        // Return the head of the modified list with pairs swapped
        return swappedHead;
    }
};