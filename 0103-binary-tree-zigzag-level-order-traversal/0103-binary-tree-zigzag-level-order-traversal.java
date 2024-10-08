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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        int c = 1;
        List<List<Integer>> ans = new ArrayList<>();
        Queue<TreeNode> q = new ArrayDeque<>();

        if(root == null) return ans;

        q.add(root);

        while(!q.isEmpty()){
            List<Integer> level = new ArrayList<>();
            int sz = q.size();

            for(int i = 0; i < sz; i++){
                TreeNode temp = q.poll();

                level.add(temp.val);

                if(temp.left != null) q.add(temp.left);
                if(temp.right != null) q.add(temp.right);
            }
            if(c%2 == 0){
                 Collections.reverse(level); 
            }
            c++;

            ans.add(level);
        }

        return ans;
    }
}