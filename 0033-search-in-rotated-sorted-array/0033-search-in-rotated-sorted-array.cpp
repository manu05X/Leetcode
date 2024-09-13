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
            // Case 2: subarray on mid's left is sorted
            else if (nums[mid] >= nums[lo]) 
            {
                //might be in the left half. Continue with the left half
                if(target >= nums[lo] && target < nums[mid])
                {
                    hi = mid-1;
                }
                //move on with the right half
                else{
                    lo = mid+1;
                }
                
            }
            // Case 3: subarray on mid's right is sorted
            else 
            {
                //might be in the right half
                if(target <= nums[hi] && target > nums[mid])
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