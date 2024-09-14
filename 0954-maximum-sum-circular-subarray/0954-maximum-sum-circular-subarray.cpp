class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int total = 0;
        int maxSum = nums[0], currMax = 0;
        int minSum = nums[0], currMin = 0;

        for(int i = 0; i < nums.size(); i++){
            currMax = max(currMax+nums[i], nums[i]);
            maxSum = max(currMax, maxSum);

            currMin = min(currMin+nums[i], nums[i]);
            minSum = min(currMin, minSum);

            total += nums[i];
        }

        return maxSum > 0 ? max(maxSum, total-minSum) : maxSum;
    }
};