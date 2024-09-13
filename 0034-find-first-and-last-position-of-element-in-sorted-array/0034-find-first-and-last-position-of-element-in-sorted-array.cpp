class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0; // start ptr
        int h = n-1; // end ptr
        
        vector<int> ans(2,-1); // ans vector
        if(n < 1)
            return ans;

        while(l < h)
        {
            // finding middle
            int m = (l+h)/2; 
            // if element at mid index is less than target
            if(nums[m] < target)
            {
                // change low ptr to mid +1
                l = m+1;
            }
            else
            {
                // change high ptr to mid
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
            // finding middle
            int m = (l+h)/2 + 1;
            // if element at mid index is greter than target
            if(nums[m] > target)
            {
                //change the high to mid-1
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


/*

0 1 2 3 4  5
5,7,7,8,8,10 

5/2 = 2

*/