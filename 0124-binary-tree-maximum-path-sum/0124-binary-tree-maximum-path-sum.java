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
    public int maxPathSum(TreeNode root) {
        int maxPathSum = Integer.MIN_VALUE;

        dfs(root, maxPathSum);

        return maxPathSum;
    }

    public int dfs(TreeNode root, int maxPathSum){
        if(root == null){
            return 0;
        }

        int getFromLeft = Math.max(dfs(root.left, maxPathSum), 0);
        int getFromRight = Math.max(dfs(root.right, maxPathSum), 0);

        maxPathSum = Math.max(maxPathSum, getFromLeft + root.val + getFromRight);

        return Math.max(getFromLeft+root.val, getFromRight+root.val);
    }
}
*/

class Solution {
    // Declare maxPathSum as a class-level (instance) variable
    private int maxPathSum;

    public int maxPathSum(TreeNode root) {
        // Initialize maxPathSum with a very low value
        maxPathSum = Integer.MIN_VALUE;

        // Call the DFS function
        dfs(root);

        // Return the global maxPathSum value
        return maxPathSum;
    }

    // DFS function that calculates the max path sum
    public int dfs(TreeNode root) {
        if (root == null) {
            return 0;  // Base case: If node is null, return 0
        }

        // Recursively calculate the max sum we can get from the left and right subtrees
        int getFromLeft = Math.max(dfs(root.left), 0);   // Only consider positive sums (ignore negative paths)
        int getFromRight = Math.max(dfs(root.right), 0); // Same for the right subtree

        // Calculate the path sum through the current node (using both left and right children)
        int currentPathSum = getFromLeft + root.val + getFromRight;

        // Update the global maxPathSum if the current path sum is larger
        maxPathSum = Math.max(maxPathSum, currentPathSum);

        // Return the max gain by using either left or right child + the current node's value
        return Math.max(getFromLeft + root.val, getFromRight + root.val);
    }
}
