class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        
        vector<int> LIS(n, 1);   // Length of LIS ending at each index
        vector<int> count(n, 1); // Number of LIS ending at each index

        int maxLength = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (LIS[j] + 1 > LIS[i]) {
                        LIS[i] = LIS[j] + 1;
                        count[i] = count[j]; // reset the count
                    } else if (LIS[j] + 1 == LIS[i]) {
                        count[i] += count[j]; // add the count
                    }
                }
            }
            maxLength = max(maxLength, LIS[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (LIS[i] == maxLength) {
                ans += count[i];
            }
        }

        return ans;
    }
};
