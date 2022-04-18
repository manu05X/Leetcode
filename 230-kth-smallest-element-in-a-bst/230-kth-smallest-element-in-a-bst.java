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
    public int ans = -1, cnt= 0;
    public void inordered(TreeNode root, int k){
        if(root == null)
            return;
        
        inordered(root.left,k);
        cnt++;
        
        if(cnt == k)
            ans = root.val;
        
        inordered(root.right,k);
        
    }
    public int kthSmallest(TreeNode root, int k) {
        int cnt = 0;
        
        
        inordered(root,k);
        
        return ans;
    }
}