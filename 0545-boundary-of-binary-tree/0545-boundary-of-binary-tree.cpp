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
    vector<int> ans;
    void printLeft(TreeNode* root)
    {
        // If the current node root is NULL, Or (it has no left or right child)
        if(!root || (!root->left && !root->right))
        {
            return;
        }
        // The value of the current node is added to the ans vector because it is part of the left boundary.
        ans.push_back(root->val);
        // If the current node does not have a left child, the function moves to the right child.
        if(!root->left)
            printLeft(root->right);
        else
            printLeft(root->left);
    }

    void printLeaf(TreeNode* root)
    {
        if(!root) return;
        printLeaf(root->left);

        if(!root->left && !root->right)
        {
            ans.push_back(root->val);
        }
        printLeaf(root->right);
    }

    void printRight(TreeNode* root)
    {
        // If the current node root is NULL, Or (it has no left or right child)
        if(!root || (!root->left && !root->right))
        {
            return;
        }
        // // If the current node does not have a right child, the function moves to the left child.
        if(!root->right)
            printRight(root->left);
        else
            printRight(root->right);
        
        ans.push_back(root->val);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root)
            return ans;
        ans.push_back(root->val);

        printLeft(root->left);
        printLeaf(root->left);
        printLeaf(root->right);
        printRight(root->right);

        return ans;
    }
};
/*

Execution:
Root Node: Add 1 to ans. ans = [1].

Left Boundary:
Traverse left subtree starting from 2:
Add 2 to ans. ans = [1, 2].
Traverse left subtree of 4:
Add 4 to ans. ans = [1, 2, 4].

Leaf Nodes:
Perform in-order traversal:
Leftmost leaf: Add 7 to ans. ans = [1, 2, 4, 7].
Right child of 4: Add 8 to ans. ans = [1, 2, 4, 7, 8].
Right child of 5: Add 5 to ans. ans = [1, 2, 4, 7, 8, 5].
Rightmost leaf: Add 6 to ans. ans = [1, 2, 4, 7, 8, 5, 6].

Right Boundary:
Traverse right subtree starting from 3:
Add 3 to a temporary list. Temp = [3].
Append temp in reverse order to ans. ans = [1, 2, 4, 7, 8, 5, 6, 3].

Output: [1, 2, 4, 7, 8, 5, 6, 3]


__________________________________________________________________________
Algorithm: Boundary Traversal of a Binary Tree
The goal is to collect the boundary nodes of a binary tree in a specific order:

    Root Node
    Left Boundary (excluding leaf nodes)
    Leaf Nodes (from left to right)
    Right Boundary (excluding leaf nodes, in reverse order)

Steps:
Start with the root node:
    Add the root value to the result if it is not NULL.

Collect the left boundary:
    Traverse down the left subtree, excluding leaf nodes.
    Add the value of each node encountered to the result.

Collect leaf nodes:
    Perform an in-order traversal of the tree.
    Add a node to the result only if it has no children (leaf node).

Collect the right boundary:
    Traverse down the right subtree, excluding leaf nodes.
    Add the value of each node encountered to a temporary list (to handle reverse order).
    Append the temporary list to the result after the traversal.

Return the combined result.

*/
