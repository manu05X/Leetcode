class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = -1, missing = 1;
    
    // Iterate through the array
    for (int i = 0; i < nums.size(); i++) {
        int n = nums[i];
        
        // If the number at the absolute value of n minus 1 is negative, we found the duplicate
        if (nums[abs(n) - 1] < 0) {
            dup = abs(n);
        } else {
            // Mark the visited number by negating its value
            nums[abs(n) - 1] *= -1;
        }
    }

    // Iterate through the modified array to find the missing number
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > 0) {
            missing = i + 1;
        }
    }

    // Return the result as a vector
    return {dup, missing};

    }
};