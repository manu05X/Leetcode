class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        // Step 1: Sort the numbers to enable prefix sum calculation
        sort(nums.begin(), nums.end());

        // Step 2: Convert the array into a prefix sum array
        // Now nums[i] represents sum of first i+1 elements
        for(int i = 1; i < n; i++){
            nums[i] = nums[i-1] + nums[i];
        }

        vector<int> ans;  // To store answers for all queries

        // Step 3: Process each query
        for(int x : queries){
            // Find the first position where prefix sum exceeds x
            // upper_bound gives iterator to first element > x
            int index = upper_bound(nums.begin(), nums.end(), x) - nums.begin();

            // The index represents the count of numbers whose sum ≤ x
            ans.push_back(index);
        }

        return ans;
    }
};