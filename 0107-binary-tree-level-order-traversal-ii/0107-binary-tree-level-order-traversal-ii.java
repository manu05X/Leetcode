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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null){
            return ans;
        }

        Deque<TreeNode> q = new ArrayDeque<>();
        q.add(root);

        while(!q.isEmpty()){
            List<Integer> temp = new ArrayList<>();

            int sz = q.size();
            for(int i = sz; i > 0; i--)
            {
                TreeNode currNode = q.poll();

                temp.add(currNode.val);

                if(currNode.left != null){
                    q.add(currNode.left);
                }
                if(currNode.right != null){
                    q.add(currNode.right);
                }
            }
            ans.addFirst(temp);
        }
        return ans;
    }
}