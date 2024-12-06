class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<vector<int>> ans;

        if(n == 0){
            ans.push_back(vector<int>{lower, upper});
            return ans;
        }

         // Check for any missing numbers between the lower bound and nums[0].
        if(lower < nums[0]){
             ans.push_back(vector<int>{lower, nums[0]-1});
        }

        // Check for any missing numbers between successive elements of nums.
        for(int i = 0; i < n-1; i++){
            if(nums[i+1] - nums[i] <= 1){
                continue;
            }
            ans.push_back(vector<int>{nums[i]+1, nums[i+1]-1});
        }

        // Check for any missing numbers between the last element of nums and
        // the upper bound.
         if(upper > nums[n-1]){
             ans.push_back(vector<int>{nums[n-1]+1, upper});
        }

        return ans;
    }
};