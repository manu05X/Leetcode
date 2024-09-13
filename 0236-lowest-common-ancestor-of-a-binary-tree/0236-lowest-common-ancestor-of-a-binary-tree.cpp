/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /*
 EXPLANATION
We'll do just normal tree traversal of the given binary tree recursivly.

For finding LCA (lowest common ancestor) we've following conditions for every node in the tree,

But before that, this solutions works under the assumption that both Node 'p' & Node 'q' will present in the tree...

if single one of the node is present in the tree, it'll not work or simply return null.

CONDITIONS: -

if current node is present in same tree as 'p' OR 'q'.

if one of it's subtrees contains 'p' and other 'q' (subtrees means, left_sub_tree and right_sub_tree).

if one of it's subtree contains both 'p' & 'q'.

if none of it's subtrees contains any of 'p' & 'q'.

Note: that's a tricky implementation, but works well under the assumption that 'p' & 'q' will be definitely present.

 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr || root == p || root == q)
            return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left == nullptr)
            return right;
        else if(right == nullptr)
            return left;
        else
            return root;
    }
};