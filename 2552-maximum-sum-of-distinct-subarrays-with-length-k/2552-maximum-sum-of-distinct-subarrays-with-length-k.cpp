class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long windowSum = 0;
        unordered_map<int, int> freqMap; // Map to store frequency of elements

        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            // Add nums[right] to the window
            windowSum += nums[right];
            freqMap[nums[right]]++;

            int currWindowSize = right - left + 1;

            // Shrink the window if it exceeds size k
            while (currWindowSize > k) {
                windowSum -= nums[left];
                freqMap[nums[left]]--;

                // Remove element from map if its frequency becomes zero
                if (freqMap[nums[left]] == 0) {
                    freqMap.erase(nums[left]);
                }
                // increase left pointer
                left++;
                //update the currWindowSize
                currWindowSize = right - left + 1;
            }

            // Update maxSum if the window size is k and all elements are distinct
            if (currWindowSize == k && freqMap.size() == k) {
                maxSum = max(maxSum, windowSum);
            }
        }

        return maxSum;
    }
};

/*
nums = [1,5,4,2,9,9,9], k = 3
        0,1,2,3,4,5,6

r = 0, l = 0, currWindowSize = 1 <= k, windowSum = 1, freqMap = {1:1}
r = 1, l = 0, currWindowSize = 2 <= k, windowSum = 6, freqMap = {1:1}{5:1}
r = 2, l = 0, currWindowSize = 3 <= k, windowSum = 10, freqMap = {1:1}{5:1}{4:1}
r = 3, l = 0, currWindowSize = 4 > k, windowSum = 10-1+2=11 ,l = 1 , freqMap = {5:1}{4:1}{2:1}


*/