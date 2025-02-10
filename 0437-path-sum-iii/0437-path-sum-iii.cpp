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
    int count = 0; // Global counter for valid paths

    void dfs(TreeNode* root, long long currentSum, int targetSum, unordered_map<long long, int>& prefixSum) {
        if (root == NULL) return;

        // Add the current node value to the running sum
        currentSum += root->val;

        // Check if a sub-path sum equals targetSum
        if (prefixSum.find(currentSum - targetSum) != prefixSum.end()) {
            count += prefixSum[currentSum - targetSum];
        }

        // Store the current prefix sum in the map
        prefixSum[currentSum]++;

        // Recursively call DFS on left and right children
        dfs(root->left, currentSum, targetSum, prefixSum);
        dfs(root->right, currentSum, targetSum, prefixSum);

        // Backtrack: Remove current node’s contribution before returning to the parent
        prefixSum[currentSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefixSum; 
        prefixSum[0] = 1; // To count cases where the path itself equals `targetSum`
        dfs(root, 0, targetSum, prefixSum);
        return count;
    }
};