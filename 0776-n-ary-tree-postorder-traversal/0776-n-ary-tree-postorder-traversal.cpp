/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void traversePost(Node* currRoot, vector<int>& ans){
        if(currRoot == NULL){
            return;
        }

        // First, visit all children
        for(Node* x : currRoot->children){
            traversePost(x, ans);
        }

         // Then, add the current node's (root's) value 
        ans.push_back(currRoot->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> ans;

        if(root == NULL){
            return ans;
        }
        traversePost(root, ans);
        return ans;
    }
};

/*
Post order

l, r, Root 

*/