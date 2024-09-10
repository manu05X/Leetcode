class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int answer = 1;

        // Use a traditional for loop instead of range-based for loop
        for (int i = 0; i < arr.size(); ++i) {
            int a = arr[i];
            int beforeA;
            
            // Check if the previous value exists in the map
            if (dp.find(a - difference) != dp.end()) {
                beforeA = dp[a - difference];
            } else {
                beforeA = 0;
            }
            
            // Update the dp map with the new value
            dp[a] = beforeA + 1;
            
            // Update the answer with the maximum value
            if (dp[a] > answer) {
                answer = dp[a];
            }
        }

        return answer;
    }
};