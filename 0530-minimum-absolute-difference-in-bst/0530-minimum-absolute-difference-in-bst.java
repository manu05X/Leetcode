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
    int minDiffrence = Integer.MAX_VALUE;
    TreeNode prevNode;

    public void inOrderTraversal(TreeNode node){
        if(node == null){
            return ;
        }

        inOrderTraversal(node.left);
        if(prevNode != null){
            minDiffrence = Math.min(minDiffrence, Math.abs(prevNode.val - node.val));
        }

        prevNode = node;
        inOrderTraversal(node.right);
    }

    public int getMinimumDifference(TreeNode root) {
        inOrderTraversal(root);
        return minDiffrence;
    }
}