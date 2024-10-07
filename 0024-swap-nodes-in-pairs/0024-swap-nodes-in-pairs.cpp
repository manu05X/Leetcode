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
        ListNode* dummyNode = new ListNode(0);//[0]
        dummyNode->next = head; // 0->1->2->3->4

        // Use 'previousNode' to keep track of the last node of the previous pair
        ListNode* prev = dummyNode; //0->1->2->3->4

        // 'currentNode' will be used to iterate through the original list
        ListNode* curr = head; //1->2->3->4

        // Proceed with swapping pairs while there are at least two nodes left to process
        while (curr && curr->next) {
            // Identify the node to be swapped with the current node
            ListNode* temp = curr->next; //1st =>1->2->3->4 temp = 2->3->4 ||2nd=> curr = 3->4->null, temp = 4->null

            // Swap the pair by reassigning pointers
            curr->next = temp->next; //1st  1->3->4 ||2nd=> 3->null
            temp->next = curr; //1st  2->1->3->4 ||2nd=> 4->3->null
            prev->next = temp; //1st  0->2->1->3->4 ||2nd=> 1->4->3->null

            // Move 'previousNode' pointer forward to the current node after swap
            prev = curr; //1st  1->3->4 ||2nd=> 3->null

            // Move 'currentNode' pointer forward to the next pair
            curr = curr->next; // 3->4 ||2nd=> null
            //dummyNode = [0->2->1->3->4->null] ||2nd=>  [0->2->1->4->3->null]
        }

        // The 'dummyNode.next' now points to the head of the modified list
        ListNode* swappedHead = dummyNode->next; //[2->1->4->3->null]

        // Clean up memory by deleting the dummy node
        delete dummyNode;

        // Return the head of the modified list with pairs swapped
        return swappedHead;
    }
};