class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int right = 0;
        int maxBeauty = 0;

        for(int left = 0; left < n; left++){
            while(right < n && nums[right] - nums[left] <= 2*k){
                right++;
            }

            maxBeauty = max(maxBeauty, right-left);
        }

        return maxBeauty;
    }
};