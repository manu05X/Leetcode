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

/*
 class Solution {
    public int pathSum(TreeNode root, int targetSum) {
        if (root == null) return 0;

        // Count paths starting from this node
        int count = countPaths(root, targetSum);
        
        // Recursively check left and right subtrees for paths
        count += pathSum(root.left, targetSum);
        count += pathSum(root.right, targetSum);
        
        return count;
    }
    
    private int countPaths(TreeNode node, int remainingSum) {
        if (node == null) return 0;

        int count = 0;
        
        // Check if current node value matches the remaining sum exactly
        if (node.val == remainingSum) {
            count++;
        }

        // Recur for left and right subtrees with the remaining sum reduced by node's value
        count += countPaths(node.left, remainingSum - node.val);
        count += countPaths(node.right, remainingSum - node.val);
        
        return count;
    }
}
*/


class Solution {
    public int pathSum(TreeNode root, int targetSum) 
    {
        if (root == null)
            return 0;
        
        return getSum(root, targetSum, 0) + pathSum(root.left, targetSum) + pathSum(root.right, targetSum);
    }
    
    public int getSum(TreeNode root, int targetSum, long sum) 
    {
        int res = 0;
        if (root == null)
            return res;
        
        sum += root.val;
        
        if (sum == targetSum)
            res++;
        
        res += getSum(root.left, targetSum, sum);
        res += getSum(root.right, targetSum, sum);
        
        sum -= root.val;
        
        return res;
    } 
}