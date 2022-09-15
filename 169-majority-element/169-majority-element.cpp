class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0, c = 1;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[res] == nums[i])
            {
                c++;
            }
            else
                c--;
            if(c == 0)
            {
                res = i;
                c = 1;
            }
        }
        c = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[res] == nums[i])
                c++;
        }
        if(c <= n/2)
            res= -1;
        
        return nums[res];
    }
};