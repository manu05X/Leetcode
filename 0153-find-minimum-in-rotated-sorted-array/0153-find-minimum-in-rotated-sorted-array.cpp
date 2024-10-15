class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size(); 

        if (nums[0] <= nums[size - 1]) 
        {
            return nums[0];
        }
      
        int lo = 0; 
        int hi = size - 1; 
      
        // Binary search to find the pivot, the smallest element
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2; 

            if (nums[0] <= nums[mid]) {
                lo = mid + 1;
            } 
            else 
            { 
                hi = mid;
            }
        }

        return nums[lo];
    }
};