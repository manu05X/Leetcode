class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReachable = 0;
        int n = nums.size();

        for(int i = 0; i < n; i++){
             // If the current index is greater than the maximum reachable index,
            // it means we cannot proceed further, so return false.
            if(maxReachable < i){
                return false;
            }
            // Update the maximum reachable index if the reachable index
            // from the current position is greater than the previous max.
            maxReachable = max(maxReachable,i+nums[i]);
        }

        return true;
    }
};
/*
[2,3,1,1,4] 

i = 0,1,2,3
r = 0+2 = 2, 1+3, 2+1, 3+1,4+4
maxR=2,4,4,4,


*/