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
    int count =0;
    public void inOrder(TreeNode root, int k){

        if(root == null) return;

        if(root.left != null){
            inOrder(root.left,k);
        }
        count++;

          if(k == count){
            ans = root.val;
            return;
        }

        if(root.right != null){
            inOrder(root.right,k);
        }

    }

    public int kthSmallest(TreeNode root, int k) {
        inOrder(root,k);

        return ans;
    }
}