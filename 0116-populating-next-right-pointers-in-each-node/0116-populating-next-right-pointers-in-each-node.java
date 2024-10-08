/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
        Queue<Node> q = new ArrayDeque<>();
        if(root == null){
            return root;
        }
        q.add(root);

        while(!q.isEmpty()){
            int sz = q.size();

            for(int i = 0; i < sz; i++){
                Node temp = q.poll();

                if(i < sz-1){
                    temp.next = q.peek();
                } else {
                    temp.next = null;
                }

                if(temp.left != null){
                    q.add(temp.left);
                }

                if(temp.right != null){
                    q.add(temp.right);
                }
            }
        }

        return root;
    }
}