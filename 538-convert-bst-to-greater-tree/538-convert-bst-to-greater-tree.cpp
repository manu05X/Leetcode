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
    TreeNode* convertBST(TreeNode* root) {
        if(root== NULL)
            return NULL;
        
        int sum = 0;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        
        while(cur != NULL || !st.empty())
        {
            while(cur){
                st.push(cur);
                cur = cur->right;
            }
            cur = st.top();
            st.pop();
            
            int temp = cur->val;
            cur->val += sum;
            sum += temp;
            cur = cur->left;
        }
        return root;
    }
};