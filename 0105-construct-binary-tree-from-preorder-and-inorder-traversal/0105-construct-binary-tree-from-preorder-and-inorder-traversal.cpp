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
    // Function to build the binary tree given preorder and inorder traversals
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        int rootIdx = 0; // Index for the current root in the preorder array
        unordered_map<int,int> mp; // Hash map to store the index of each element in inorder
        
        // Populate the hash map with indices of elements in the inorder array
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;
        
        // Call the recursive helper function to construct the tree
        return built(preorder, inorder, rootIdx, 0, inorder.size()-1, mp);
    }
    
    // Recursive function to build the tree
    TreeNode* built(vector<int>& preorder, vector<int>& inorder, int &rootIdx, int l, int r, unordered_map<int,int> &mp) 
    {
        // Base case: if the current subtree range is invalid (left boundary > right boundary)
        if(l > r)
            return nullptr;
        
        // Find the index of the current root node in the inorder array using the hash map
        int pivot = mp[preorder[rootIdx]];
        
        // Create a new tree node with the current root value (from inorder)
        TreeNode* node = new TreeNode(inorder[pivot]);
        
        // Increment the root index in preorder as we move to the next node
        rootIdx++;
        
        // Recursively build the left subtree (elements before the pivot in inorder)
        node->left = built(preorder, inorder, rootIdx, l, pivot - 1, mp);
        
        // Recursively build the right subtree (elements after the pivot in inorder)
        node->right = built(preorder, inorder, rootIdx, pivot + 1, r, mp);
        
        // Return the constructed node
        return node;
    }
};
