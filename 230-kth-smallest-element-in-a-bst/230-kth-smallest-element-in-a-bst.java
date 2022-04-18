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
// USING INORDERED TRAVERSAL
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

/*<----------------ITERATIVE METHOD--------------------------------------------------------------------------------------------------------->*/

class Solution {
    public int kthSmallest(TreeNode root, int k) {
        Stack<TreeNode> st = new Stack<>();
        
        TreeNode curr = root;
        while(curr != null || st.size() > 0){
            if(curr != null)
            {
                st.push(curr);
                curr= curr.left;
            }
            else
            {
                TreeNode p = st.pop();
                k--;
                
                if(k == 0)
                    return p.val;
                
                curr = p.right;
            }
        }
        
        return 0;
    }
}
