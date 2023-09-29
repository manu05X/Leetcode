class Solution {
public:
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
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();


            if(isDecrease(nums) || isIncrease(nums)){
                return true;
            }
            else
            {
                return false;
            }
    }
};