class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftSum(n,0), rightSum(n,0), ans(n,0);
        leftSum[0] = nums[0];
        rightSum[n-1] = nums[n-1]; 

        for(int i = 1; i < n; i++){
            leftSum[i] = leftSum[i-1]+nums[i];
            rightSum[n-i-1] = rightSum[n-i] + nums[n-i-1];
        }

        // cout << "LeftSum";
        // for(int i = 0; i < n; i++){
        //     cout << leftSum[i]<<" ";
        // }
        // cout <<endl;

        // cout << "ReftSum";
        // for(int i = 0; i < n; i++){
        //     cout << rightSum[i]<<" ";
        // }
        // cout <<endl;

        for(int i = 0; i < n; i++){
            ans[i] = abs(leftSum[i]-rightSum[i]);
        }


        return ans;
    }
};