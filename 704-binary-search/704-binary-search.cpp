class Solution {
public:
    int search(vector<int>& nums, int target) 
    {    
        if (nums.size() == 0) 
            return -1;
        int l = 0, h = nums.size()-1;
        while(l <= h)
        {
            int m = l + (h-l)/2;
            if(nums[m] == target)
                return m;
            if(nums[m] > target)
            {
                h = m-1;
            }
            else //if(nums[m] < target)
            {
                l = m+1;
            }   
        }
        return -1;
    }
};