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
    void helper(TreeNode* root, int & ans,int m){
        if(root == NULL) return ;
        if(root->val >= m ){
            ans++; 
            m = root->val;
        }
        if(root->left) helper(root->left,ans,m);
        if(root->right) helper(root->right,ans,m);

    }
    int goodNodes(TreeNode* root) {
        int ans = 0;
        int m = root->val;
        helper(root,ans,m);
        return ans;
    }
};