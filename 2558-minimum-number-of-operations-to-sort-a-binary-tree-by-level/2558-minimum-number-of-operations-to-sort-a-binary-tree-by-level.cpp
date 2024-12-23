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