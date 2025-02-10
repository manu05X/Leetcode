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
    public int count = 0;
    public void dfs(TreeNode root, Long currSum, int targetSum, HashMap<Long, Integer> prefixSum){
        if(root == null){
            return;
        }

        currSum += root.val;
        if(prefixSum.containsKey(currSum - targetSum) == true){
            count += prefixSum.get(currSum - targetSum);
        }

        prefixSum.put(currSum, prefixSum.getOrDefault(currSum,0)+1);

        dfs(root.left, currSum, targetSum, prefixSum);
        dfs(root.right, currSum, targetSum, prefixSum);
        
        prefixSum.put(currSum, prefixSum.getOrDefault(currSum, 0)-1);
    }

    public int pathSum(TreeNode root, int targetSum) {
        HashMap<Long, Integer> prefixSum = new HashMap<>();
        prefixSum.put(0L,1);

        dfs(root, 0L, targetSum, prefixSum);

        return count;
    }
}



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


/*
class Solution {
    // Main method to find the number of paths summing to targetSum
    public int pathSum(TreeNode root, int targetSum) {
        // If the tree is empty, return 0 as there are no paths
        if (root == null)
            return 0;
        
        // Call helper function getSum to calculate the number of valid paths starting from the current root,
        // and recursively call pathSum on the left and right children to cover all possible subtrees.
        return getSum(root, targetSum, 0) + pathSum(root.left, targetSum) + pathSum(root.right, targetSum);
    }
    
    // Helper function to calculate the number of valid paths with a given starting root node
    public int getSum(TreeNode root, int targetSum, long sum) {
        int res = 0;  // Initialize the result (count of valid paths) to 0
        if (root == null)
            return res;  // If the current node is null, return 0 (no path)

        // Add the value of the current node to the running sum
        sum += root.val;

        // If the running sum equals the targetSum, increment the result (valid path found)
        if (sum == targetSum)
            res++;

        // Recur for the left and right subtrees with the updated sum, accumulating the count of valid paths
        res += getSum(root.left, targetSum, sum);
        res += getSum(root.right, targetSum, sum);
        
        // (This is unnecessary as it's not modifying the actual sum in place. It's not used afterward.)
        sum -= root.val;
        
        return res;  // Return the total number of valid paths found for this branch
    }
}
*/