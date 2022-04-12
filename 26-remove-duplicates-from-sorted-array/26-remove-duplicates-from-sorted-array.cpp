class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return NULL;
			// taking a left indx
        int left = 0;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] != nums[left])  // if both number are not equal so,
            {
                left++; // increasing the left indx 
                nums[left] = nums[i]; // place the current num at left idx
            } 
        }   
        return left+1; // returning index + 1  as length in array start from 0
    }
};