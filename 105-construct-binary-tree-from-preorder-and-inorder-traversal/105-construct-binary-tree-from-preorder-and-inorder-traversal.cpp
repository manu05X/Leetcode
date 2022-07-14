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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int rootIdx = 0;
        unordered_map<int,int> mp;
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        
        return built(preorder, inorder,rootIdx, 0, inorder.size()-1,mp);
    }
    
    TreeNode* built(vector<int>& preorder, vector<int>& inorder, int &rootIdx, int l, int r, unordered_map<int,int> &mp) 
    {
        if(l>r)
            return nullptr;
        
        int pivot = mp[preorder[rootIdx]];
        TreeNode* node = new TreeNode(inorder[pivot]);
        rootIdx++;
        
        node->left = built(preorder, inorder,rootIdx, l, pivot-1,mp);
        
        node->right = built(preorder, inorder,rootIdx, pivot+1, r,mp);
        
        return node;
    }
    
};