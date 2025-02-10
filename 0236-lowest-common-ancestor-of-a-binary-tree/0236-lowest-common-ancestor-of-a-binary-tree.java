/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */




class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // Base case: If root is null or matches one of p or q, return root
        if (root == null || root == p || root == q) {
            return root;
        }

        // Recursively search for p and q in left and right subtrees
        TreeNode leftLCA = lowestCommonAncestor(root.left, p, q);
        TreeNode rightLCA = lowestCommonAncestor(root.right, p, q);

        // If both left and right subtrees return non-null, root is the LCA
        if (leftLCA != null && rightLCA != null) {
            return root;
        }

        // If only one subtree has a non-null result, return that result
        return (leftLCA != null) ? leftLCA : rightLCA;
    }
}