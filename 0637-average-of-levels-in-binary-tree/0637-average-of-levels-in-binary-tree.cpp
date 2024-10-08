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
    vector<double> averageOfLevels(TreeNode* root) {
        ios::sync_with_stdio(false);
        cin.tie(NULL);

        vector<double> ans; // Resultant vector to store the zigzag level order traversal
        
        // If the tree is empty, return the empty result
        if (!root) {
            return ans;
        }
        
        // Queue to perform level order traversal (Breadth-First Search, BFS)
        queue<TreeNode*> q;
        q.push(root); // Start with the root node
        
        // While there are nodes to process in the queue
        while (!q.empty()) {
            double sum = 0;
            double count = 0;
            
            queue<TreeNode*> level; // Temporary queue to store nodes at the current level
            int n = q.size(); // Number of nodes at the current level
            
            // Traverse all nodes at the current level
            for (int i = 0; i < n; i++) {
                TreeNode* curr = q.front(); // Get the front node from the queue
                q.pop(); // Remove the processed node from the original queue
                sum += curr->val;
                count++;
                
                // Push left child to the level queue if it exists
                if (curr->left) {
                    level.push(curr->left);
                }
                
                // Push right child to the level queue if it exists
                if (curr->right) {
                    level.push(curr->right);
                }
            }
            q = level; // adding the level queue to original queue
            
            // Add the current level avg (temp) to the result (ans)
            ans.push_back(sum * 1.0/ count);
        }
        
        // Return the result containing zigzag level order traversal
        return ans;
    }
};