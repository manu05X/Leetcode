class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        
        deque<int> maxDeque; // Monotonic deque for maximums
        deque<int> minDeque; // Monotonic deque for minimums
        
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            // Update maxDeque
            while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(right);

            // Update minDeque
            while (!minDeque.empty() && nums[minDeque.back()] >= nums[right]) {
                minDeque.pop_back();
            }
            minDeque.push_back(right);

            // Shrink the window if the condition is violated
            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                ++left; // Move the left pointer
                // Remove out-of-bound indices from deques
                if (!maxDeque.empty() && maxDeque.front() < left) 
                    maxDeque.pop_front();
                if (!minDeque.empty() && minDeque.front() < left) 
                    minDeque.pop_front();
            }

            // Count valid subarrays in the current window
            ans += (right - left + 1);
        }
        
        return ans;
    }
};
