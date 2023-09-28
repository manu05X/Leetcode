class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        int t = 0;

        for(int i = 0; i < n; i++)
        {
            if(nums[i]%2 == 0){
                ans[t] = nums[i];
                t++;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(nums[i]%2 == 1){
                ans[t] = nums[i];
                t++;
            }
        }

        return ans;
    }
};