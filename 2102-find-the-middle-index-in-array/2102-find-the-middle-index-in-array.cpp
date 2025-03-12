class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int rightSum = 0; 
        
        // Step 1: Calculate the total sum of the array
        for(int i = 0; i < nums.size(); i++) {
            rightSum += nums[i];  
        }

        int leftSum = 0;  // Initialize left sum to 0
        
        // Step 2: Iterate through the array to find the middle index
        for(int i = 0; i < nums.size(); i++) {
            rightSum -= nums[i];  // Subtract current element from right sum
            
            // Step 3: Check if left sum is equal to right sum
            if(leftSum == rightSum) return i;  

            leftSum += nums[i];  // Add current element to left sum
        }

        return -1; // Step 4: If no such index is found, return -1
    }
};
