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
    int ans = 0;
    int maxDepth = 0;
    void preOrder(TreeNode* root, int currHeight){
        if(root == NULL){
            return ;
        }
        if(root->left == NULL && root->right == NULL){
            if(currHeight == maxDepth){
                ans += root->val;
            }
            if(currHeight > maxDepth){
                ans = 0;
                maxDepth = currHeight;
                ans += root->val;
            }
        }

        preOrder(root->left, currHeight+1);
        preOrder(root->right, currHeight+1);

    }
    int deepestLeavesSum(TreeNode* root) {
        preOrder(root, 1);
        return ans;
    }
};