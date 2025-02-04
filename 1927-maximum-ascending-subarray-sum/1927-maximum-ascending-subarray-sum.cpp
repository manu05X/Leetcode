class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();

        int ans = INT_MIN;
        if(n == 1){
            return nums[0];
        }

        int currSum = nums[0];
        for(int i = 1; i < n; i++){
            
            if(nums[i-1] < nums[i]){
                currSum = currSum+nums[i];
                ans = max(ans, currSum);
            }
            else {
                ans = max(ans, currSum);
                currSum = nums[i];
                
            }
            
        }

        return ans == INT_MIN ? nums[0] : ans;
        // return ans;
    }
};