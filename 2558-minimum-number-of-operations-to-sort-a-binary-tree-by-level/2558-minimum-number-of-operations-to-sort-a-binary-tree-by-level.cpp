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
    // Constants for bit manipulation
    const int SHIFT = 20;
    const int MASK = 0xFFFFF;

public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> queue;
        queue.push(root);
        int swaps = 0;

        // Process tree level by level using BFS
        while (!queue.empty()) {
            int levelSize = queue.size();
            vector<long long> nodes(levelSize);

            // Store node values with encoded positions
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = queue.front();
                queue.pop();
                // Encode value and index: high 20 bits = value, low 20 bits =
                // index
                nodes[i] = (static_cast<long long>(node->val) << SHIFT) + i;

                if (node->left != nullptr) queue.push(node->left);
                if (node->right != nullptr) queue.push(node->right);
            }

            // Sort nodes by their values (high 20 bits)
            sort(nodes.begin(), nodes.end());

            // Count swaps needed to match indices with original positions
            for (int i = 0; i < levelSize; i++) {
                int origPos = static_cast<int>(nodes[i] & MASK);
                if (origPos != i) {
                    // Swap nodes and decrement i to recheck current position
                    swap(nodes[i], nodes[origPos]);
                    swaps++;
                    i--;
                }
            }
        }
        return swaps;
    }
};



/*
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        if (!root) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int count = 0;

        while (!q.empty()) {
            int sz = q.size();
            vector<int> arr(sz, 0);

            // Traverse the current level
            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front();
                q.pop();
                arr[i] = curr->val;

                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            // Calculate the minimum swaps required to sort the level
            count += minSwap(arr);
        }

        return count;
    }

    int minSwap(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> indexedArr(n);

        // Pair the values with their indices
        for (int i = 0; i < n; i++) {
            indexedArr[i] = {arr[i], i};
        }

        // Sort based on the values
        sort(indexedArr.begin(), indexedArr.end());

        // To track visited elements
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            // If the element is already visited or in the correct position
            if (visited[i] || indexedArr[i].second == i) continue;

            // Find the cycle length
            int cycleSize = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = indexedArr[j].second;
                cycleSize++;
            }

            // Add the number of swaps needed for this cycle
            if (cycleSize > 1) swaps += (cycleSize - 1);
        }

        return swaps;
    }
};

*/



/*
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            int sz = q.size();

            for(int i = 0; i < sz; i++){
                if(curr->left != NULL){
                    q.push(curr->left);
                }

                if(curr->right != NULL){
                    q.push(curr->right);
                }
            }

            vector<int> arr(sz, 0);
            int k = 0;
            for(TreeNode* num : q){
                arr[k++] = num->val;
            }

            count += minSwap(arr, k);

        }

        return count;
    }

    int minSwap(vector<int>& arr, int k){
        int ans = 0;
        vector<int> temp = arr;

        sort(temp.begin(), temp.end());

        for(int i = 0; i < k; i++){
            if(arr[i] != temp[i]){
                ans++;
                int idx = indexOf(arr, temp[i])
                swap(arr[i], arr[idx]);
            }
        }

        return ans;
    }

    int indexOf(vector<int>& arr, int elem){
        for(int i = 0; i < arr.size(); i++){
            if(arr[i] == elem){
                return i;
            }
        }
        return -1;
    }
};

*/