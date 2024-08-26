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
    private int idx = 0; // Declare idx as a class member to persist its value across recursive calls


    public TreeNode solve(int miniE, int maxE, int[] preorder){
        if(idx >= preorder.length) return null;

        if(preorder[idx] < miniE || preorder[idx] > maxE) 
            return null;

        TreeNode temp = new TreeNode(preorder[idx]);
        idx++;
        temp.left = solve(miniE, temp.val, preorder);
        temp.right = solve(temp.val, maxE ,preorder);

        return temp;

    }

    public TreeNode bstFromPreorder(int[] preorder) {
        int miniE = Integer.MIN_VALUE;
        int maxE = Integer.MAX_VALUE;

        return solve(miniE,maxE, preorder);
    }
}

/*
        8
    5
1



*/