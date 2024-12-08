class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        int x = nums[0];
        int ans = 1;


        for(int i = 1; i < n; i++){
            if(nums[i] - x <= k){
                continue;
            } else {
                x = nums[i];
                ans++;
            }
        }

        return ans;
    }
};