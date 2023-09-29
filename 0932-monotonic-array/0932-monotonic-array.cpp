class Solution {
public:
/*
bool isDecrease(vector<int>& nums)
    {
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] < nums[i])
            {
                return false;
            }
        }
        return true;
    }
       
    bool isIncrease(vector<int>& nums)
    {
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] > nums[i])
            {
                return false;
            }
        }
        return true;
    }
    */
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();

        bool increasing = true;
        bool decreasing = true;

        for(int i = 0; i < n-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                increasing = false;
            }
            if(nums[i] < nums[i+1])
            {
                decreasing = false;
            }
        }
        return decreasing || increasing;
    }
};