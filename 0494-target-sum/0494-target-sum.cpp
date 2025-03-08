class Solution {
public:
    int findTargetSumWaysRec(vector<int>& nums, int idx, int target){
         // If all integers are processed
        if(idx == nums.size()){
            // If target is reached
            if(target == 0){
                return 1;
            }
            // If target is not reached
            return 0;
        }

        // Return total count of the following cases:
        //       1. Add current element to the target
        //       2. Subtract current element from the target
        return (findTargetSumWaysRec(nums, idx+1, target-nums[idx]) + findTargetSumWaysRec(nums, idx+1, target+nums[idx]));
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return findTargetSumWaysRec(nums, 0, target);
    }
};