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
    int maxAncestorDiff(TreeNode* root) {
        if(root == NULL){
            return 0;
        }

        return helper(root, root->val, root->val);
    }

    int helper(TreeNode* root, int currMax, int currMin){
        if(root == NULL){
            return currMax-currMin;
        }

        currMax = max(root->val, currMax);
        currMin = min(root->val, currMin);

        int left = helper(root->left, currMax, currMin);
        int right = helper(root->right, currMax, currMin);

        return max(left, right);
    }
};