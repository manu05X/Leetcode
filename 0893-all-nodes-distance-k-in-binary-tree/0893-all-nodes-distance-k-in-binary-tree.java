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
    List<Integer> ans;
    public void helper(TreeNode root,int k) {
        if(root==null) return;
        if(k==0) {
            ans.add(root.val);
        }
        helper(root.left,k-1);
        helper(root.right,k-1);
    }
    public int getTarget(TreeNode root,TreeNode tar,int k) {
        if(root==null) return -1;
        if(root.val==tar.val) {
            helper(root,k);
            return k-1;
        }
        int x=getTarget(root.left,tar,k);
        if(x!=-1) {
            if(x==0)
                ans.add(root.val);
            else
                helper(root.right,x-1);
            return x-1;
        }
        x=getTarget(root.right,tar,k);
        if(x!=-1) {
            if(x==0)
                ans.add(root.val);
            else
                helper(root.left,x-1);
            return x-1;
        }
        return -1;
    }
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        ans=new ArrayList<>();
        getTarget(root,target,k);
        return ans;
    }
}



/*
class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        List<Integer> result = new ArrayList<>();
        if (root == null || target == null) return result;

        // Step 1: Build parent references using a HashMap
        Map<TreeNode, TreeNode> parentMap = new HashMap<>();
        buildParentMap(root, null, parentMap);

        // Step 2: Perform BFS from target node
        Queue<TreeNode> queue = new LinkedList<>();
        Set<TreeNode> visited = new HashSet<>();
        
        queue.add(target);
        visited.add(target);
        int distance = 0;

        while (!queue.isEmpty()) {
            if (distance == k) {
                for (TreeNode node : queue) {
                    result.add(node.val);
                }
                return result;
            }

            int size = queue.size();
            for (int i = 0; i < size; i++) {
                TreeNode current = queue.poll();

                // Explore child nodes (left & right)
                if (current.left != null && !visited.contains(current.left)) {
                    queue.add(current.left);
                    visited.add(current.left);
                }
                if (current.right != null && !visited.contains(current.right)) {
                    queue.add(current.right);
                    visited.add(current.right);
                }

                // Explore parent node
                TreeNode parent = parentMap.get(current);
                if (parent != null && !visited.contains(parent)) {
                    queue.add(parent);
                    visited.add(parent);
                }
            }
            distance++;
        }

        return result;
    }

    // Helper function to map each node to its parent
    private void buildParentMap(TreeNode node, TreeNode parent, Map<TreeNode, TreeNode> parentMap) {
        if (node == null) return;
        parentMap.put(node, parent);
        buildParentMap(node.left, node, parentMap);
        buildParentMap(node.right, node, parentMap);
    }
}
*/