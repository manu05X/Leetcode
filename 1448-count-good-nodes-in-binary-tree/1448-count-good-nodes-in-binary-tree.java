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
    public int goodNodes(TreeNode root) {
        return DFS(root, Integer.MIN_VALUE);
    }
    
    public int DFS(TreeNode node, int max)
    {
        int res = 0;
        if(node == null)
            return 0;
        if(node.val >= max)
            res = 1;
        res += DFS(node.right, Math.max(max,node.val));
        res += DFS(node.left, Math.max(max,node.val));
        return res;
    }
}