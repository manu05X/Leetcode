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

    public TreeNode recoverFromPreorder(String traversal) {
        // List to track the last node at each depth
        List<TreeNode> levels = new ArrayList<>();
        int index = 0, n = traversal.length();

        while (index < n) {
            // Count depth (number of dashes)
            int depth = 0;
            while (index < n && traversal.charAt(index) == '-') {
                depth++;
                index++;
            }

            // Extract node value
            int value = 0;
            while (index < n && Character.isDigit(traversal.charAt(index))) {
                value = value * 10 + (traversal.charAt(index) - '0');
                index++;
            }

            // Create the new node
            TreeNode node = new TreeNode(value);

            // Adjust levels list to match the current depth
            if (depth < levels.size()) {
                levels.set(depth, node);
            } else {
                levels.add(node);
            }

            // Attach the node to its parent
            if (depth > 0) {
                TreeNode parent = levels.get(depth - 1);
                if (parent.left == null) {
                    parent.left = node;
                } else {
                    parent.right = node;
                }
            }
        }

        // The root node is always at index 0
        return levels.get(0);
    }
}