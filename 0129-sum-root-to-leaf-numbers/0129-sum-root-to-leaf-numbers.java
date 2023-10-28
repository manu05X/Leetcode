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
    int ans = 0;
    public void preOrder(TreeNode root, int currSum){
        if(root != null){
            currSum = currSum *10 + root.val;

            if(root.left == null && root.right == null){
                ans += currSum;
            }

            preOrder(root.left, currSum);
            preOrder(root.right, currSum);
        }
    }
    public int sumNumbers(TreeNode root) {
        preOrder(root, 0);
        return ans;
    }
}