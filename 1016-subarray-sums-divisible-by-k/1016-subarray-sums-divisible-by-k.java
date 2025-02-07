class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        // Array to store frequency of remainders
        int[] remainderCount = new int[k];
        remainderCount[0] = 1; // Initialize for cases where prefix sum itself is divisible by k

        int cumulativeSum = 0;
        int countSubarraySum = 0;

        for (int num : nums) {
            // Compute the cumulative sum
            int x = cumulativeSum + num;
            
            // Normalize the remainder to always be positive
            cumulativeSum = (x % k + k) % k;

            // If this remainder was seen before, it contributes to valid subarrays
            countSubarraySum += remainderCount[cumulativeSum];

            // Increment the count of this remainder
            remainderCount[cumulativeSum]++;
        }
        
        return countSubarraySum;
    }
}



/*

import java.util.HashMap;

class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();

        int cumulativeSum = 0;
        int countSubarraySum = 0;

        // Initialize the map with remainder 0 to handle cases where prefix sum itself is divisible by k
        mp.put(0, 1);

        for (int i = 0; i < n; i++) {
            cumulativeSum += nums[i];

            // Ensure remainder is always non-negative
            int remainder = (cumulativeSum % k + k) % k;

            // If remainder exists in the map, add its count to the result
            if (mp.containsKey(remainder)) {
                countSubarraySum += mp.get(remainder);
            }

            // Update the count of this remainder in the map
            mp.put(remainder, mp.getOrDefault(remainder, 0) + 1);
        }

        return countSubarraySum;
    }
}


*/