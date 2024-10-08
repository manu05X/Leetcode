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
    vector<vector<int>> ans; // Initialize ans list

    void dfs(TreeNode* root, int targetSum, vector<int>& temp){
        if(root == NULL)
            return;
        
        temp.push_back(root->val); // Add current node to temp
        targetSum -= root->val; // Subtract current node's value from targetSum

        if(root->left == NULL && root->right== NULL){
            if(targetSum == 0){
                ans.push_back(temp); // Add a copy of temp to ans
            }
        } else {
            // Recur for left and right children
            dfs(root->left, targetSum, temp);
            dfs(root->right, targetSum, temp);
        }

        temp.pop_back(); // Backtrack to explore other paths
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        dfs(root, targetSum, temp);

        return ans;
    }
};