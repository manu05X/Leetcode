class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size(); 

        if (nums[0] <= nums[size - 1]) 
        {
            return nums[0];
        }
      
        int left = 0; 
        int right = size - 1; 
      
        // Binary search to find the pivot, the smallest element
        while (left < right) {
            int mid = left + (right - left) / 2; 

            if (nums[0] <= nums[mid]) {
                left = mid + 1;
            } 
            else 
            { 
                right = mid;
            }
        }

        return nums[left];
    }
};