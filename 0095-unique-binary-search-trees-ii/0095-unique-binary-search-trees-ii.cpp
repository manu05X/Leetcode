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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return constructBSTs(1, n);
    }
    
private:
    vector<TreeNode*> constructBSTs(int start, int end) {
        vector<TreeNode*> trees;
        if (start > end) {
            trees.push_back(nullptr); // Empty subtree case
            return trees;
        }
        
        // Pick each number as root
        for (int i = start; i <= end; i++) {
            // Generate all left and right subtrees
            vector<TreeNode*> leftTrees = constructBSTs(start, i - 1);
            vector<TreeNode*> rightTrees = constructBSTs(i + 1, end);
            
            // Combine left and right trees with root `i`
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    trees.push_back(root);
                }
            }
        }
        return trees;
    }
};
