class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        
        // Check if merging is possible
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }
        
        // Prefix sum array for quick range sum calculation
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }
        
        // DP table initialization
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // We need to consider segments of increasing length
        for (int len = k; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                
                // Try all possible partitions where we can merge
                for (int m = i; m < j; m += k - 1) {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
                }
                
                // If we can merge the entire segment into one pile
                if ((j - i) % (k - 1) == 0) {
                    dp[i][j] += prefix[j + 1] - prefix[i];
                }
            }
        }
        
        return dp[0][n - 1];
    }
};



/*
class Solution {
public:
    int mergeStonesHelper(vector<int>& stones, int k, int current_cost) {
        int n = stones.size();
        
        // Base case: only one pile left
        if (n == 1) {
            return current_cost;
        }
        
        // Impossible case
        if (n < k) {
            return -1;
        }
        
        int min_cost = INT_MAX;
        
        // Try merging every possible k consecutive piles
        for (int i = 0; i <= n - k; i++) {
            vector<int> new_stones(stones);
            
            // Calculate the cost of merging stones[i..i+k-1]
            int merge_cost = 0;
            for (int j = i; j < i + k; j++) {
                merge_cost += new_stones[j];
            }
            
            // Merge the k piles into one
            new_stones.erase(new_stones.begin() + i, new_stones.begin() + i + k);
            new_stones.insert(new_stones.begin() + i, merge_cost);
            
            // Recursively process the new configuration
            int total_cost = mergeStonesHelper(new_stones, k, current_cost + merge_cost);
            
            // Update minimum cost if we found a valid solution
            if (total_cost != -1) {
                min_cost = min(min_cost, total_cost);
            }
        }
        
        return (min_cost == INT_MAX) ? -1 : min_cost;
    }

    int mergeStones(vector<int>& stones, int k) {
        return mergeStonesHelper(stones, k, 0);
    }
};
*/