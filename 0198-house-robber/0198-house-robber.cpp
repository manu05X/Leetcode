class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n < 2){
            return nums[0];
        }
        
        vector<int> ans(n+1,0);

        ans[0] = nums[0];
        ans[1] = max(nums[1],nums[0]);

        for(int i = 2; i < n; i++){
            ans[i] = max(ans[i-1], ans[i-2]+nums[i]);
        }
        return ans[n-1];
    }
};
/*
2,7,9,3,1

2,7,11,11,12

2,1,1,2

2,2,3,4

*/