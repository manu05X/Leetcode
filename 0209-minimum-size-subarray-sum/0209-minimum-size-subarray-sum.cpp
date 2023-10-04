class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        // Initialize start pointer to 0 and sum to 0
        int start = 0, total = 0;
        // Initializing windowSize to a max number
        int windowSize = INT_MAX;

        // Iterate over the input array
        for(int i = 0; i < n; i++)
        {
            total += nums[i];
            // check if we can remove elements from the start side of the subarray
            // while still satisfying the target condition
            while(total >= target)
            {
                // Finding size of current subarray
                int currWindow = (i+1) - start;
                windowSize = min(windowSize, currWindow);
                total -= nums[start];
                start += 1;
            }
        }

        if(windowSize != INT_MAX)
            return windowSize;
        else
            return 0;
    }
};