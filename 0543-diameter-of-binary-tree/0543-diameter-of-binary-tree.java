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
    int dia = 0;
    int height(TreeNode root){
        if(root == null){
            return 0; // Base case: Null nodes have a depth of 0
        }

        // Recursively calculate the left and right subtree depths
        int lh = height(root.left);
        int rh = height(root.right);

        // Update the diameter. The path passing through this node will be the sum of the depths of the left and right subtrees.
        dia = Math.max(dia, lh+rh);

        // Return the height of the current node
        return Math.max(rh,lh)+1;
    }
    public int diameterOfBinaryTree(TreeNode root) {
        dia = 0;
        // Calculate the depth while updating the diameter
        height(root);

        return dia;
    }
}