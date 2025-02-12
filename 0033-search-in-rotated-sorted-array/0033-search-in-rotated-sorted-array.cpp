class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        
        // Binary search to find the peak element
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            // Case 1: find target
            if(nums[mid] == target)
            {
                return mid;
            }
            // Case 2: subarray on mid's left is sorted so element nums[lo] is less or equal to nums[mid]
            else if (nums[lo] <= nums[mid]) 
            {
                //might be in the left half. Continue with the left half
                if(nums[lo] <= target && target < nums[mid])
                {
                    hi = mid-1;
                }
                //move on with the right half
                else{
                    lo = mid+1;
                }
                
            }
            // Case 3: subarray on mid's right is sorted so element nums[mid] is less or equal to nums[hi]
            else 
            {
                //might be in the right half so 
                if(nums[mid] < target && target <= nums[hi])
                {
                    lo = mid+1;
                }
                //move on with the left half 
                else
                {
                    hi = mid-1;
                }
            }
        }
        return -1;
    }
};