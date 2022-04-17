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
    TreeNode* increasingBST(TreeNode* root) {
         stack<TreeNode*> s;
        TreeNode* temp = root;
        TreeNode* ans=NULL;
        TreeNode* curr;
        while(true){
            if(temp){
                s.push(temp);
                temp=temp->left;
            }
            else{
                if(s.empty()) break;
                temp = s.top();
                s.pop();
                if(!ans){
                    ans = curr = temp;
                }
                else{
                    curr->right=temp;
                    curr->right->left=NULL;
                    curr=curr->right;
                }
                temp = temp->right;
            }
        }
        curr->right=NULL;
        return ans;
    }
};