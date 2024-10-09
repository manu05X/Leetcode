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

    public TreeNode findMin(TreeNode root){
        while (root.left != null) {
            root = root.left;
        }
        return root;
    }

    public TreeNode deleteNode(TreeNode root, int key) {
        // Base case: if the tree is empty or the key is not found
        if (root == null) {
            return root;
        }
        
        // If the key to be deleted is smaller than root's key, search the left subtree
        if (key < root.val) {
            root.left = deleteNode(root.left, key);
        } 
        // If the key to be deleted is greater than root's key, search the right subtree
        else if (key > root.val) {
            root.right = deleteNode(root.right, key);
        } 
        // Key is same as root's key, so this is the node to be deleted
        else {
            // Case 1: Node with only one child or no child
            if (root.left == null) {
                return root.right;
            } 
            else if (root.right == null) {
                return root.left;
            }

            // Case 2: Node with two children
            // Get the inorder successor (smallest in the right subtree)
            TreeNode minNode = findMin(root.right);
            
            // Copy the inorder successor's value to this node
            root.val = minNode.val;
            
            // Delete the inorder successor from the right subtree
            root.right = deleteNode(root.right, minNode.val);
        }
        
        return root;
    }
}