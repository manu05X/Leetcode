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
    pair<int, int> robHelper(TreeNode* root) {
        if (!root) return {0, 0};  // Base case: If node is NULL, both values are 0

        // Post-order traversal: Compute left and right subtrees first
        pair<int, int> left = robHelper(root->left);
        pair<int, int> right = robHelper(root->right);

        // If we rob this node, we cannot rob its direct children
        int rob = root->val + left.first + right.first;

        // If we don't rob this node, we can choose the max profit from children
        int notRob = max(left.first, left.second) + max(right.first, right.second);

        return {notRob, rob};  // Return both cases
    }

    int rob(TreeNode* root) {
        pair<int, int> result = robHelper(root);
        return max(result.first, result.second);  // Max profit from root
    }
};
