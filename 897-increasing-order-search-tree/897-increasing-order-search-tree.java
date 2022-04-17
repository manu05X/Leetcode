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
    TreeNode curr;
    public TreeNode increasingBST(TreeNode root) {
        TreeNode ans = new TreeNode(0);
        curr = ans;
        inorder(root);
        
        return ans.right;
    }
    public void inorder(TreeNode root){
        if(root == null)
            return;
        inorder(root.left);
        root.left = null;
        curr.right = root;
        curr = root;
        inorder(root.right);
    }
    
}
/*<---------------------------------------------------------------------------------------------------------------------->*/
// Itration Solution

class Solution {
    public TreeNode increasingBST(TreeNode root) {
        if (root == null) 
            return root;
        Deque<TreeNode> dq = new ArrayDeque<>();
        TreeNode cur = root;
        TreeNode prev = null;
        TreeNode newRoot = null;
        
        while (!dq.isEmpty() || cur != null) 
        {
            //keep going left, until you hit a null
            while (cur != null) {
                dq.offer(cur);
                cur = cur.left;
            }
            
            // pop from the stack and create the new root if not already created.
            cur = dq.pollLast();
            if (newRoot == null) 
            {
                newRoot = cur;
            }
            
            //assign the current element to previous element's right.
            if (prev != null) 
            {
                prev.right = cur;
                cur.left = null;
            }
            //point prev to cur and move cur to right.
            prev = cur;
            cur = cur.right;
        }
        return newRoot;
    }
}
