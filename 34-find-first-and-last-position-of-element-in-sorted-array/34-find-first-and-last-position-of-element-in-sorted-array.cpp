class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int firstOccurrance = findBound(nums, target, true);
        if(firstOccurrance == -1)
        {
            return {-1,-1};
        }
        int lastOccurance = findBound(nums, target, false);
        
        return {firstOccurrance,lastOccurance};
    }
    
    int findBound(vector<int> nums, int target, bool isFirst)
    {
        int n = nums.size();
        int l = 0, h = n-1;
        
        while(l <= h)
        {
            int m = (l+h)/2;
            if(nums[m] == target)
            {
                if(isFirst)
                {
                    // condition for lower bound
                    if(m == l || nums[m-1] != target)
                    {
                        return m;
                    }
                    h = m - 1;
                }
                else
                {
                    // condition for upper bound
                    if(m == h || nums[m+1] != target)
                    {
                        return m;
                    }
                    l = m + 1;
                }
            }
            else if(nums[m] > target)
            {
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        return -1;
    }
};