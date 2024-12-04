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
    int diameter; // Variable to store the maximum diameter

    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0; // Base case: Null nodes have a depth of 0
        }
        
        // Recursively calculate the left and right subtree depths
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // Update the diameter. The path passing through this node will be the sum of the depths of the left and right subtrees.
        diameter = max(diameter, leftDepth + rightDepth);
        
        // Return the height of the current node
        return 1 + max(leftDepth, rightDepth);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        diameter = 0; // Initialize the diameter
        maxDepth(root); // Calculate the depth while updating the diameter
        return diameter; // Return the maximum diameter
    }
};
