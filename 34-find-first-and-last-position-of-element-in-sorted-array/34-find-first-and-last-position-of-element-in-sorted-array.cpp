class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0;
        int h = n-1;
        
        vector<int> ans(2,-1);
        if(n < 1)
            return ans;
        while(l < h)
        {
            int m = (l+h)/2;
            if(nums[m] < target)
            {
                l = m+1;
            }
            else
            {
                h = m;
            }
        }
        
        if(nums[l] != target)
        {
            return ans;
        }
        else
        {
            ans[0] = l;
        }
        
        h = n-1;
        while(l < h)
        {
            int m = (l+h)/2 + 1;
            if(nums[m] > target)
            {
                h = m-1;
            }
            else
            {
               l = m;
            }
        }
        ans[1] = h;
        
        return ans;
    }
};