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
    int minDifference = Integer.MAX_VALUE; // To store the minimum absolute difference
    TreeNode prevNode; // To keep track of the previous node during in-order traversal

    // Function to perform in-order traversal of the BST
    public void inOrderTraversal(TreeNode node) {
        // Base case: If the current node is null, return
        if (node == null) {
            return;
        }

        // Traverse the left subtree
        inOrderTraversal(node.left);

        // If there is a previous node, calculate the absolute difference
        if (prevNode != null) {
            minDifference = Math.min(minDifference, Math.abs(prevNode.val - node.val));
        }

        // Update the previous node to the current node
        prevNode = node;

        // Traverse the right subtree
        inOrderTraversal(node.right);
    }

    // Main function to calculate the minimum absolute difference
    public int getMinimumDifference(TreeNode root) {
        inOrderTraversal(root); // Start in-order traversal from the root
        return minDifference; // Return the smallest difference found
    }
}
