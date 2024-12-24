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
    int ans = 0; // Variable to store the sum of the deepest leaves.
    int maxDepth = 0; // Variable to track the maximum depth encountered so far.

    // Preorder traversal to find the sum of the values of the deepest leaves.
    void preOrder(TreeNode* root, int currHeight) {
        // Base case: If the node is null, return.
        if (root == NULL) {
            return;
        }

        // If the current node is a leaf (both left and right children are null).
        if (root->left == NULL && root->right == NULL) {
            // If the current height equals the maximum depth encountered so far, add the node's value to the sum.
            if (currHeight == maxDepth) {
                ans += root->val;
            }

            // If the current height is greater than the maximum depth, update the maximum depth,
            // reset the sum, and add the current node's value.
            if (currHeight > maxDepth) {
                ans = 0; // Reset sum since we found a new deeper level.
                maxDepth = currHeight; // Update the maximum depth.
                ans += root->val; // Add the current node's value.
            }
        }

        // Recursively traverse the left subtree, increasing the height.
        preOrder(root->left, currHeight + 1);

        // Recursively traverse the right subtree, increasing the height.
        preOrder(root->right, currHeight + 1);
    }

    // Function to calculate the sum of the values of the deepest leaves.
    int deepestLeavesSum(TreeNode* root) {
        // Start the traversal from the root node with an initial height of 1.
        preOrder(root, 1);
        return ans; // Return the sum of the deepest leaves.
    }
};
