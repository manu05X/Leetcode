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
    bool isSymmetricUtil(TreeNode* root1,TreeNode* root2)
    {
        if(root1 == NULL && root2 == NULL)
            return true;
        if(root1 == NULL || root2 == NULL)
            return false;
        return (root1 ->val == root2 -> val) && isSymmetricUtil(root1 -> left, root2->
  right) && isSymmetricUtil(root1 -> right, root2 -> left);

    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isSymmetricUtil(root->left, root->right);
    }
};

/*
The tree's symmetry means the left subtree of one tree should mirror the right subtree of the other tree and vice versa. For the tree to remain symmetric:

The left child of root1 should match the right child of root2.
The right child of root1 should match the left child of root2.

        1
       / \
      2   2
     / \ / \
    3  4 4  3

Step 1: Check if root == NULL. False, proceed.
Step 2: Call isSymmetricUtil(root->left, root->right):
    Compare root1 = 2 and root2 = 2. Equal, proceed.
    Call isSymmetricUtil(root1->left, root2->right):
        Compare root1 = 3 and root2 = 3. Equal, proceed.
        Call isSymmetricUtil(NULL, NULL) twice. Both return true.
    Call isSymmetricUtil(root1->right, root2->left):
        Compare root1 = 4 and root2 = 4. Equal, proceed.
        Call isSymmetricUtil(NULL, NULL) twice. Both return true.
    Result for the current subtree is true.
Step 3: Similarly, process the mirrored subtrees:
    isSymmetricUtil(root1->right, root2->left) (left = 4, right = 4) -> true.
Final Result: The tree is symmetric.

*/