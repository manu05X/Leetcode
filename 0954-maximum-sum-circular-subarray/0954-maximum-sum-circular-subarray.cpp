class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Disable synchronization between C++ and C standard streams for faster input/output
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);  // Untie cin from cout for faster input processing
        cout.tie(nullptr); // Untie cout from cin for faster output processing
        
        // Variables to store the total sum of the array, the maximum subarray sum, and the minimum subarray sum
        int total = 0;
        int maxSum = nums[0], currMax = 0; // maxSum is initialized to the first element, currMax tracks the current max subarray sum
        int minSum = nums[0], currMin = 0; // minSum is initialized to the first element, currMin tracks the current min subarray sum

        // Traverse the array and calculate max subarray, min subarray, and total sum
        for(int i = 0; i < nums.size(); i++){
            // Calculate the current max subarray sum ending at index i
            // Either add the current element to the previous subarray or start a new subarray from the current element
            currMax = max(currMax + nums[i], nums[i]);
            // Update the overall max subarray sum
            maxSum = max(currMax, maxSum);

            // Calculate the current min subarray sum ending at index i
            // Either add the current element to the previous subarray or start a new subarray from the current element
            currMin = min(currMin + nums[i], nums[i]);
            // Update the overall min subarray sum
            minSum = min(currMin, minSum);

            // Add the current element to the total sum of the array
            total += nums[i];
        }

        // If the maximum subarray sum is greater than 0, return the maximum of:
        // 1) the maximum subarray sum without wrapping
        // 2) the total sum minus the minimum subarray sum (which gives the max subarray sum with wrapping)
        // If all numbers are negative (maxSum <= 0), return the max subarray sum without wrapping.
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }

};

/*
1.Calculate the Total Sum of the Array:
The total sum is simply the sum of all elements in the array.

2. Find the Maximum Subarray Sum without Wrapping:
Use Kadane’s Algorithm to find the maximum sum subarray in the normal (non-circular) case.

3. Find the Minimum Subarray Sum:
Use a modified version of Kadane’s Algorithm to find the minimum sum subarray. This helps us in the wrapped case.

4. Compute the Wrapped Subarray Sum:
The sum of the wrapped subarray is calculated by subtracting the minimum subarray sum from the total sum: Wrapped sum=Total sum−Minimum subarray sum

5.Final Result:
The final result is the maximum of:
The maximum subarray sum (non-wrapped).
The wrapped subarray sum:-  Result=max(maxSum,Total sum−minSum)

However, if the maximum subarray sum is less than or equal to 0 (i.e., all elements are negative), we return the non-wrapped maximum sum, because wrapping wouldn't help in such cases.

*/