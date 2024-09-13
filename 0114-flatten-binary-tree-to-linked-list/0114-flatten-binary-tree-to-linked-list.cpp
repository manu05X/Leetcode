/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Function to flatten a binary tree into a linked list in place
    void flatten(TreeNode* root) {
        // Base case: if the root is null, there's nothing to flatten
        if(root == NULL)
            return;
        
        // Pointer to traverse the tree starting from the root
        TreeNode* ptr = root;
        
        // Traverse the tree using a while loop
        while(ptr != NULL)
        {
            // If the current node has a left child
            if(ptr->left != NULL)
            {
                // Find the rightmost node in the left subtree
                TreeNode* rightmost = ptr->left;
                while(rightmost->right != NULL){
                    rightmost = rightmost->right;
                }
                
                // Attach the original right subtree of the current node 
                // to the rightmost node in the left subtree
                rightmost->right = ptr->right;
                
                // Move the left subtree to the right
                ptr->right = ptr->left;
                
                // Set the left pointer of the current node to null since we are flattening the tree
                ptr->left = NULL;
            }
            
            // Move to the right subtree (which could be the original right subtree or the left subtree moved to the right)
            ptr = ptr->right;
        }
    }
};
