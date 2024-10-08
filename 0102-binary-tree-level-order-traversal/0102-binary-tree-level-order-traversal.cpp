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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int sz = q.size();
            vector<int> level;

            for(int i = 0; i < sz; i++){
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp->val);

                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }

            ans.push_back(level);
        }

        return ans;
    }
};



/* 
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        vector<vector<int>> ans;
        dfs(root, ans,0);

        return ans;
    }
};
*/