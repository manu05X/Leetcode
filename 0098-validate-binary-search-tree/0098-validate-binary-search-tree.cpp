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
     bool isValidBST(TreeNode* root) {
        return validBst(root, LONG_MIN, LONG_MAX);
    }
    bool validBst(TreeNode* root, long min, long max) {
        if (!root) 
        {
            return true;
        }
        //out of range 
        if (root->val <= min || root->val >= max) {
            return false;
        }
        // cheking with both left and right root
        return validBst(root->left, min, root->val) && validBst(root->right, root->val, max);
    }
};