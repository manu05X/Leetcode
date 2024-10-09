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
    public int getHeight(TreeNode root){
        if(root == null) return 0;

        int lh = getHeight(root.left);
        int rh = getHeight(root.right);

        // left, right subtree is unbalanced or cur tree is unbalanced
        if(lh == -1 || rh == -1 || Math.abs(lh-rh) > 1){
            return -1;
        }

        return Math.max(lh,rh)+1;
    }
    public boolean isBalanced(TreeNode root) {
        int h = getHeight(root);

        return h != -1;
    }
}