class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        
        int count = 0, left = 0, ans = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 == 1) k--;  // Decrease k when an odd number is encountered
            
            while (k < 0) {  // If we have more than k odd numbers, shrink the window
                if (nums[left] % 2 == 1) k++;  
                left++;
            }
            
            ans += (right - left + 1); // Count all valid subarrays ending at `right`
        }
        
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};