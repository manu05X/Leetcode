/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        int currRootVal = root.val;
        int pVal = p.val;
        int qVal = q.val;

        // If both p and q are lesser than parent
        if(pVal < currRootVal && qVal < currRootVal){
            return lowestCommonAncestor(root.left, p, q);
        }
        // If both p and q are greater than parent 
        else if(pVal > currRootVal && qVal > currRootVal){
            return lowestCommonAncestor(root.right, p, q);
        } else {
            // We have found the split point, i.e. the LCA node.
            return root;
        }
    }
}