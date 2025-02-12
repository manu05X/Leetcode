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
            /*
            If nums[0] <= nums[mid], this means that the first half of the array (from nums[0] to nums[mid]) is sorted, so the minimum element must be in the right half. Therefore, we move lo to mid + 1.
            */
            // if (nums[0] <= nums[mid]) {
            //     lo = mid + 1;
            // }
            /*
            If nums[0] > nums[mid], it means the pivot is in the left half (from lo to mid), so we move hi to mid.
            */
            // else 
            // { 
            //     hi = mid;
            // }
            /*
            nums[mid] < nums[hi] this means that the first half of the array (from nums[0] to nums[mid]) is sorted,
            so the minimum element must be in the left half. Therefore, we move hi to mid.
            */
            if (nums[mid] < nums[hi]) 
            {
                /*
                If nums[mid] < nums[hi], the right half (from mid+1 to hi) is sorted, and the pivot (the smallest element) must be in the left half or at mid. Therefore, the search space is reduced by setting hi = mid.
                */
                hi = mid;
            }
            /*
            If nums[mid] >= nums[hi], it means the left half is sorted, and the smallest element is in the right half. So, we move the lo pointer to mid + 1 to continue searching in the right half.
            */
            else
            {
                lo = mid+1;
            }
        }

        return nums[lo];
    }
};

/*
0,1,2,3,4
3,4,5,1,2

lo = 0, hi = 4, mid = 2, 5 < 2 , so lo = 3
lo = 3, hi = 4, mid = 3, 1 < 2 X, so hi = 3
lo = 3, hi = 3 break while loop

return nums[lo]

nums[3] = 3

*/