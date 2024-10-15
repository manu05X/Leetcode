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

            // if (nums[0] <= nums[mid]) {
            //     lo = mid + 1;
            // } 
            // else 
            // { 
            //     hi = mid;
            // }
            /*
            If nums[0] <= nums[mid], this means that the first half of the array (from nums[0] to nums[mid]) is sorted, so the minimum element must be in the right half. Therefore, we move lo to mid + 1.
            */
            if (nums[mid] < nums[hi]) 
            {
                hi = mid;
            } 
            else
            /*
            If nums[0] > nums[mid], it means the pivot is in the left half (from lo to mid), so we move hi to mid.
            */
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

lo = 0, hi = 4, mid = 2, 5 < 2 , so hi = 2
lo = 0, hi = 2, mid = 1, 4 < 2 X, so lo = 2
lo = 2, hi = 2, mid = 2, 5 < 2 X, so lo = 2+1 = 3



*/