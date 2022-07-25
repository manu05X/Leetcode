class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() < 1)
            return {-1,-1};
        int st = lower_bound(nums, target);
        int end = lower_bound(nums, target+1)-1;
        
        if(st < nums.size() && nums[st] == target)
            return {st,end};
        else
            return {-1,-1};
    }
    
    int lower_bound(vector<int>& nums, int target)
    {
        int l = 0;
        int h = nums.size()-1;
        
        while(l<=h)
        {
            int m = l+(h-l)/2;
            if(nums[m] < target)
                l = m+1;
            else
                h = m-1;
        }
        
        return l;
    }
};