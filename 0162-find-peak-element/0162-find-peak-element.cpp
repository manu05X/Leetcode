class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size()-1;

        while(lo < hi){
            int mid = lo +(hi-lo)/2;
            // If the middle element is less than its successor,
            // the peak is in the right half, excluding the mid element
            if(nums[mid] < nums[mid+1]){
                lo = mid+1;
            }
            else{
                // If the middle element is greater than or equal to its successor,
                // the peak is in the left half
                hi = mid;
            }
        }

        return lo;
    }
};