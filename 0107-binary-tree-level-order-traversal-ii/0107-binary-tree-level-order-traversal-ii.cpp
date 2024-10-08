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
    void dfs(TreeNode* root, vector<vector<int>>& ans, int lvl)
    {
        if(root == NULL){
            return ;
        }

        if(ans.size() <= lvl){
            ans.push_back({});
        }

        ans[lvl].push_back(root->val);
        lvl++;

        dfs(root->left, ans,lvl);
        dfs(root->right,ans,lvl);

    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        if(root==NULL){
            return {};
        }
        vector<vector<int>> ans;
        dfs(root, ans,0);

        reverse(ans.begin(), ans.end());

        return ans;
    }
    // vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
    // }
};