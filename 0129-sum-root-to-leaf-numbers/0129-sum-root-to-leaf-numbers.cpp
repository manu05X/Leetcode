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
    // Variable to store the total sum of all root-to-leaf paths
    int rootToLeaf = 0;

    // Pre-order traversal function to compute the sum of all root-to-leaf numbers
    void preOrder(TreeNode* root, int curr){
        // If the current node is not null, proceed
        if(root != NULL)
        {
            // Update the current value by multiplying it by 10 and adding the current node's value
            // This forms the number represented by the path from the root to the current node
            curr = curr*10 + root->val;

            // Check if the current node is a leaf (no left and right children)
            if(root->left == NULL && root->right == NULL)
            {
                // Add the current value (number formed by the root-to-leaf path) to the total sum
                rootToLeaf += curr;
            }

            // Recursively traverse the left subtree
            preOrder(root->left, curr);

            // Recursively traverse the right subtree
            preOrder(root->right, curr);
        }
    }

    // Main function to compute the sum of all root-to-leaf numbers
    int sumNumbers(TreeNode* root) {
        // Start the pre-order traversal with an initial current value of 0
        preOrder(root,0);

        // Return the final sum of all root-to-leaf numbers
        return rootToLeaf;
    }
};
