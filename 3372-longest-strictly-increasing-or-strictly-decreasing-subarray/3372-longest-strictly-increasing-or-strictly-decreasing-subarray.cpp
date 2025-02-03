class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int countInc = 1;
        int countDec = 1;

        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]){
                countInc++;
                countDec = 1;
            } else if(nums[i] > nums[i-1]){
                countDec++;
                countInc = 1;
            } else{
                 countInc = 1;
                 countDec = 1;
            }

            ans = max(ans, max(countDec, countInc));
        }

        return ans;
    }
};