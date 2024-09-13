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

/*
Example:
Preorder traversal: [3, 9, 20, 15, 7]
Inorder traversal: [9, 3, 15, 20, 7]

Step-by-Step Process:
Preorder and Inorder Traversal:

Preorder gives the root first: 3 is the root.
Inorder gives the left and right subtrees with the root in the middle: [9, 3, 15, 20, 7]. We find that 3 splits the left subtree [9] and right subtree [15, 20, 7].

We build a hash map from the inorder traversal to quickly find the index of any element:
Hash Map mp: mp = {9: 0, 
                   3: 1, 
                   15: 2, 
                   20: 3, 
                   7: 4}

Recursive Tree Construction:
Start with rootIdx = 0 (which points to 3 in preorder).
Root:

The root is 3, and we split the inorder array based on the position of 3.
Left subtree: [9]
Right subtree: [15, 20, 7]
Left Subtree:

Move to rootIdx = 1 (preorder value 9). Since 9 is a leaf node (no left or right in inorder), create a node with 9 and return.
Right Subtree:

Move to rootIdx = 2 (preorder value 20).
Left subtree of 20: [15]
Right subtree of 20: [7]
Left Subtree of 20:

Move to rootIdx = 3 (preorder value 15). Create the node for 15 (leaf node).
Right Subtree of 20:

Move to rootIdx = 4 (preorder value 7). Create the node for 7 (leaf node).
Final Tree Structure: The final tree looks like this:
    3
   / \
  9  20
     /  \
    15   7

Key Points:
Preorder gives the root nodes.
Inorder helps in splitting the left and right subtrees.
A hash map (mp) speeds up searching the root index in the inorder array, making the construction efficient.

*/
