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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> mp;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            mp[curr->val]++;

            if(curr->left != NULL){
                q.push(curr->left);
            }

            if(curr->right != NULL){
                q.push(curr->right);
            }
        }

        int maxFreq = 0;
        for(auto i : mp){
            maxFreq = max(maxFreq, i.second);
        }

        vector<int> ans;
        for(auto x : mp){
            if(x.second == maxFreq){
                ans.push_back(x.first);
            }
        }

        return ans;
    }
};

/*
Algorithm

1. Initialize a hash map counter and a queue queue that     contains root.

2   Perform a BFS. While queue is not empty:
        Pop node from the front of queue.
        Increment the frequency of node.val in counter.
        If node.left is not null, push it to queue.
        If node.right is not null, push it to queue.

3. Find the maximum value in counter as maxFreq.
4. Initialize the answer list ans.
5. Iterate over all key-value pairs in counter. If the value is equal to maxFreq, add the key to ans.
6. Return ans.

*/