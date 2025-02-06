class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int left = 0, pro = 1;
        if (k <= 1) return 0;

        for(int right = 0; right < n; right++)
        {
            // Update the product by multiplying the rightmost element
            pro *= nums[right]; // 10, 50, 100, 60
            // While the product is equal to or larger than k, 
            // increment the left pointer to reduce the product 
            // and contract the window size from the left
            while(left <= right and pro >= k){
                pro = pro/nums[left]; // 100/10=> 10,
                left++; // 1
            }
            // The number of subarrays with a product less than k 
            // that end with nums[right] is equal to the size of the current window
            ans += right-left+1; //1, 1+2, 3+2, 5+3
        }
        return ans; // 8
    }
};