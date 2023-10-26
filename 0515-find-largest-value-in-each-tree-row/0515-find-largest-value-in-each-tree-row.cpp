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
    vector<int> largestValues(TreeNode* root) {
        if (root == nullptr) {
            return vector<int>{};
        }

        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int length = q.size();
            int currElem = INT_MIN;

            for(int i = 0; i < length; i++)
            {
                TreeNode* currNode = q.front();
                q.pop();
                currElem = max(currElem, currNode->val);

                if(currNode->left){
                    q.push(currNode->left);
                }

                if(currNode->right){
                    q.push(currNode->right);
                }
            }
            ans.push_back(currElem);
        }

        return ans;
    }
};