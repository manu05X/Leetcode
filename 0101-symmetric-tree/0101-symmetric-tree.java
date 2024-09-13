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
    // Function to check if the binary tree is symmetric
    public boolean isSymmetric(TreeNode root) {
        // Using a queue to perform level-order traversal in pairs
        Queue<TreeNode> q = new LinkedList<>();
        
        // Add the root twice to the queue (to compare the left and right subtrees)
        q.add(root);
        q.add(root);

        // Continue processing until the queue is empty
        while (!q.isEmpty()) {
            // Remove two nodes from the queue to compare them
            TreeNode t1 = q.poll();
            TreeNode t2 = q.poll();

            // If both nodes are null, they are symmetric at this position
            if (t1 == null && t2 == null) 
                continue; // Skip this pair and continue to the next
            
            // If one of them is null (and the other is not), it's not symmetric
            if (t1 == null || t2 == null)
                return false;
            
            // If the values of the two nodes are not the same, it's not symmetric
            if (t1.val != t2.val)
                return false;

            // Add the children of the nodes to the queue in opposite order
            // For the left subtree of t1, compare it with the right subtree of t2
            q.add(t1.left);
            q.add(t2.right);
            
            // For the right subtree of t1, compare it with the left subtree of t2
            q.add(t1.right);
            q.add(t2.left);
        }

        // If all node comparisons are valid, the tree is symmetric
        return true;
    }
}
