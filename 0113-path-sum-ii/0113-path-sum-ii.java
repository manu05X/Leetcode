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
    List<List<Integer>> ans = new ArrayList<>(); // Initialize ans list

    void dfs(TreeNode root, int targetSum, List<Integer> temp) {
        if (root == null) return;

        temp.add(root.val); // Add current node to temp
        targetSum -= root.val; // Subtract current node's value from targetSum

        // If we reach a leaf node, check if targetSum is 0
        if (root.left == null && root.right == null) {
            if (targetSum == 0) {
                ans.add(new ArrayList<>(temp)); // Add a copy of temp to ans
            }
        } else {
            // Recur for left and right children
            dfs(root.left, targetSum, temp);
            dfs(root.right, targetSum, temp);
        }

        temp.remove(temp.size() - 1); // Backtrack to explore other paths
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<Integer> temp = new ArrayList<>();
        dfs(root, targetSum, temp);
        return ans;
    }
}
