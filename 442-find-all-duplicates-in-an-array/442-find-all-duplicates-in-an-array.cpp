class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            int idx = abs(nums[i]);
            if(nums[idx-1] < 0)
            {
                ans.push_back(abs(nums[i]));
            }
            nums[idx-1] = -nums[idx-1];
        }
        return ans;
    }
};
/*
i = 0, [4,3,2,-7,8,2,3,1]      // change the sign of element at 4th index
i = 1, [4,3,-2,-7,8,2,3,1]     // change the sign of element at 3rd index
i = 2, [4,-3,-2,-7,8,2,3,1]    // change the sign of element at 2nd index
i = 3, [4,-3,-2,-7,8,2,-3,1]   // change the sign of element at 7th index
i = 4, [4,-3,-2,-7,8,2,-3,-1]   // change the sign of element at 8th index
i = 5, [4,3,-2,-7,8,2,-3,-1]    // here before changing the sign of element at 2nd index we will realize that it is already negative, which implies that 2 has appeared before in the array. So, we will push 2 in the ans
i = 6, [4,3,2,-7,8,2,-3,-1]     // again we will encounter a negative element at 3rd index and we will push 3 into our ans
i = 7, [-4,3,-2,-7,8,2,-3,-1]   // change the sign of element at 1st index
*/