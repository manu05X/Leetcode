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
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> ans = new ArrayList<>();
        Queue<TreeNode> q = new ArrayDeque<>();

        if(root == null) return ans;

        q.add(root);

        while(!q.isEmpty()){
            long sum = 0;
            long count = 0;

            Queue<TreeNode> level = new ArrayDeque<>();
            int sz = q.size();

            for(int i = 0; i < sz; i++){
                TreeNode temp = q.poll();
                sum += temp.val;
                count++; 

                if(temp.left != null) level.add(temp.left);
                if(temp.right != null) level.add(temp.right);
            }
            q = level;

            ans.add(sum * 1.0/count);
        }

        return ans;
    }
}