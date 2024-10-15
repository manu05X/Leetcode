/*
class Solution {
public:

bool isDecrease(vector<int>& nums)
    {
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] < nums[i])
            {
                return false;
            }
        }
        return true;
    }
       
    bool isIncrease(vector<int>& nums)
    {
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i-1] > nums[i])
            {
                return false;
            }
        }
        return true;
    }
    */
    
    
    /*
    
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();

        bool increasing = true;
        bool decreasing = true;

        for(int i = 0; i < n-1; i++)
        {
            if(nums[i] > nums[i+1])
            {
                increasing = false;
            }
            
            if(nums[i] < nums[i+1])
            {
                decreasing = false;
            }
        }
        return decreasing || increasing;
    }
};

*/

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 1) {
            return true; // A single element array is considered monotonic.
        }
        
        int left = 0;
        int right = n - 1;
        
        while (left < n - 1 && nums[left] == nums[left + 1]) {
            left++; // Skip identical elements at the beginning.
        }
        
        while (right > 0 && nums[right] == nums[right - 1]) {
            right--; // Skip identical elements at the end.
        }
        
        if (left >= right) {
            return true; // All elements are identical; the array is monotonic.
        }
        
        bool increasing = nums[left] < nums[left + 1];
        
        for (int i = left; i < right; i++) {
            if (increasing && nums[i] > nums[i + 1]) {
                return false; // Not monotonic if it decreases.
            } else if (!increasing && nums[i] < nums[i + 1]) {
                return false; // Not monotonic if it increases.
            }
        }
        
        return true;
    }
};