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
    // Function to determine if there's a root-to-leaf path in the binary tree where the sum of the node values equals the targetSum
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: if the current node (root) is null, there's no path, so return false
        if(root == NULL)
            return false;
        
        // Subtract the value of the current node from the targetSum
        targetSum -= root->val;
        
        // Check if the current node is a leaf node (no left or right children)
        // If it is a leaf, check if the targetSum is now 0
        if((root->left == NULL) && (root->right == NULL))
            return (targetSum == 0);  // Return true if the targetSum equals 0, meaning the path sum matches
        
        // Recurse to the left and right subtrees, checking if either of them has a path sum that equals the updated targetSum
        return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
    }
};
