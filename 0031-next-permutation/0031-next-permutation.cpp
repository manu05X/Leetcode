class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int p1 = -1, p2 = -1; // taking two index

        if(n < 2) return; // if size is less than 2

        //traversing the array in reverse order
        for(int i = n-2; i >= 0; i--)
        {
            //traversing the nums arry in reverse order 
            //to find the first index where nums[i] < nums[i+1]
            if(nums[i] < nums[i+1])
            {
                p1 = i;
                break;
            }
        }

        // if p1 < 0 so, we have arry of decreasing order
        if(p1 < 0)
        {
            reverse(nums.begin(), nums.end());
        }
        // we find 2nd index where nums[p1] < nums[i] traversing from back
        else
        {
            for(p2 = n-1; p2 > p1; p2--)
            {
                if(nums[p2] > nums[p1])
                {
                    // swap both number at index p1,p2
                    swap(nums[p2],nums[p1]);
                    break;
                }
            }
            
            reverse(nums.begin()+p1+1, nums.end());
        }
    }
};