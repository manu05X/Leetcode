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
    void convertTree(TreeNode* &root, int &sum) {
        if (root == NULL) return;

        convertTree(root->left, sum);
        int currNodeVal = root->val;
        root->val = sum;
        sum-=currNodeVal;
        convertTree(root->right, sum);
    }
    int getSum(TreeNode* root) {
        if (root == NULL) return 0;

        return getSum(root->left) + root->val + getSum(root->right);
    }
    // int getSum(TreeNode* root) {
    //     if (root == NULL) return 0;

    //     int old_val = root->val;

    //     root->val = getSum(root->left)+getSum(root->right);

    //     return root->val+old_val;
    // }
    TreeNode* bstToGst(TreeNode* root) {
        int nodeSum = getSum(root);

        convertTree(root, nodeSum);
        return root;
    }
};