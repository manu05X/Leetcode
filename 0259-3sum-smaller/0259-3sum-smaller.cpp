class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        int n = nums.size();

        // Sort the array
        std::sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                // If the sum is less than the target, all pairs (left, right) will also satisfy the condition
                if (sum < target) {
                    count += right - left;
                    ++left; // Move left pointer to the right
                } else {
                    --right; // Move right pointer to the left
                }
            }
        }

        return count;
    }
};