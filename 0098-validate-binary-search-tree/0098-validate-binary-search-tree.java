/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    // This function recursively checks if the tree rooted at 'root' is a valid BST.
    // 'min' is the lower bound, and 'max' is the upper bound for the node's value.
    public boolean backtracking(TreeNode root, long min, long max) {
        // Base case: if the node is null, we've reached the end of a branch, and it's valid.
        if (root == null) return true;

        // If the current node's value violates the BST property (not within min and max bounds),
        // return false. A node's value must be greater than 'min' and less than 'max'.
        if (root.val <= min || root.val >= max) return false;

        // Recursively check the left and right subtrees:
        // - The left subtree must have all values less than the current node's value, so we
        //   update the 'max' bound to be 'root.val'.
        // - The right subtree must have all values greater than the current node's value, so we
        //   update the 'min' bound to be 'root.val'.
        // If both subtrees are valid, then the whole tree is valid.
        return backtracking(root.left, min, root.val) && backtracking(root.right, root.val, max);
    }

    // This is the main function that starts the validation process.
    public boolean isValidBST(TreeNode root) {
        // We start the validation with the whole range of valid values.
        // Since we're checking an integer tree, we use 'Long.MIN_VALUE' and 'Long.MAX_VALUE' to avoid
        // issues with integer overflow or when the tree contains Integer.MIN_VALUE or Integer.MAX_VALUE.
        return backtracking(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}
