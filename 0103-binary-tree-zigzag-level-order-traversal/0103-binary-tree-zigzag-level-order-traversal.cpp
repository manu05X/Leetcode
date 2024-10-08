/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Function to perform zigzag level order traversal of a binary tree
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        int c = 1; // Counter to keep track of the level (odd/even) for zigzag traversal
        vector<vector<int>> ans; // Resultant vector to store the zigzag level order traversal
        
        // If the tree is empty, return the empty result
        if (!root) {
            return ans;
        }
        
        // Queue to perform level order traversal (Breadth-First Search, BFS)
        queue<TreeNode*> q;
        q.push(root); // Start with the root node
        
        // While there are nodes to process in the queue
        while (!q.empty()) {
            vector<int> temp; // Temporary vector to store nodes at the current level
            int n = q.size(); // Number of nodes at the current level
            
            // Traverse all nodes at the current level
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front(); // Get the front node from the queue
                temp.push_back(curr->val);  // Add the node's value to the temporary vector
                
                // Push left child to the queue if it exists
                if (curr->left) {
                    q.push(curr->left);
                }
                
                // Push right child to the queue if it exists
                if (curr->right) {
                    q.push(curr->right);
                }
                
                q.pop(); // Remove the processed node from the queue
            }
            
            // If the current level is even (c % 2 == 0), reverse the order of nodes for zigzag effect
            if (c % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }
            
            c++; // Increment level counter for the next level
            
            // Add the current level nodes (temp) to the result (ans)
            ans.push_back(temp);
        }
        
        // Return the result containing zigzag level order traversal
        return ans;
    }
};
