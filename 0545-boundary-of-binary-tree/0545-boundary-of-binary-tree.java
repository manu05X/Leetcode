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
    List<Integer> ans = new ArrayList<>();
    public void leftBoundry(TreeNode root){
        if(root == null || (root.left == null && root.right == null)){
            return ;
        }

        ans.add(root.val);

        if(root.left != null){
            leftBoundry(root.left);
        } else {
            leftBoundry(root.right);
        }
    }

    public void leafBoundry(TreeNode root){
        if(root == null){
            return ;
        }

        leafBoundry(root.left);

        if(root.left == null && root.right == null){
            ans.add(root.val);
        }
        leafBoundry(root.right);
    }


    public void rightBoundry(TreeNode root){
        if(root == null || (root.left == null && root.right == null)){
            return ;
        }

        if(root.right != null){
            rightBoundry(root.right);
        } else {
            rightBoundry(root.left);
        }
        ans.add(root.val);
    }

    public List<Integer> boundaryOfBinaryTree(TreeNode root) {
        if(root == null){
            return ans;
        }
        ans.add(root.val);

        leftBoundry(root.left);
        leafBoundry(root.left);
        leafBoundry(root.right);
        rightBoundry(root.right);
        
        return ans;
    }
}