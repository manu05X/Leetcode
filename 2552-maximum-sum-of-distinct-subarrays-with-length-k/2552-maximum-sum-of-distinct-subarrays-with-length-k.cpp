
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long windowSum = 0;
        unordered_map<int, int> freqMap; // Map to store frequency of elements

        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            // Add nums[right] to the windowSum
            windowSum += nums[right];
            // Add the current element to the map
            freqMap[nums[right]]++;

            int currWindowSize = right - left + 1; // current window size

            // Shrink the currWindow Size if it exceeds size k
            while (currWindowSize > k) {
                windowSum -= nums[left]; // Subtract the left element from windowSum
                freqMap[nums[left]]--; // Remove the left element from freqMap

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
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = 0, windowSum = 0;
        unordered_map<int, int> freqMap; // Map to store frequency of elements

        for (int right = 0; right < n; right++) {
            // Add the current element to the map and update the window sum
            freqMap[nums[right]]++;
            windowSum += nums[right];

            int lefptr = right-k+1; // sometime this may be negative

            // If the window size exceeds k, adjust the left side of the window
            if (freqMap.size() <= k && leftptr >= 0) {
                // We have a window of exactly size k, check if it's valid and update maxSum
                if (freqMap.size() == k) {
                    maxSum = max(maxSum, windowSum);
                }
            } else {
                // Remove the leftmost element (like in lengthOfLongestSubstringKDistinct)
                freqMap[nums[leftptr]]--;
                windowSum -= nums[leftptr];
                
                // If the frequency of the leftmost element becomes 0, remove it from the map
                if (freqMap[nums[leftptr]] == 0) {
                    freqMap.erase(nums[leftptr]);
                }
            }
        }

        return maxSum;
    }
};
*/

/*
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long maxSum = 0, windowSum = 0;
        unordered_map<int, int> freqMap; // Map to store frequency of elements

        for (int right = 0; right < n; right++) {
            // Add the current element to the map and update the window sum
            freqMap[nums[right]]++;
            windowSum += nums[right];

            // If we have a window size of exactly k, check if it meets the conditions
            if (right - k + 1 >= 0) {  // This ensures the left pointer is valid
                // Check if the window is valid (i.e., all elements are distinct)
                if (freqMap.size() == k) {
                    maxSum = max(maxSum, windowSum);  // Update maxSum if valid
                }

                // Slide the window by removing the leftmost element
                int lefptr = right - k + 1;
                windowSum -= nums[lefptr];
                freqMap[nums[lefptr]]--;
                
                // Remove the element from the map if its frequency becomes zero
                if (freqMap[nums[lefptr]] == 0) {
                    freqMap.erase(nums[lefptr]);
                }
            }
        }

        return maxSum;
    }
};
*/



/*

nums = [1,5,4,2,9,9,9], k = 3
        0,1,2,3,4,5,6

r = 0, l = 0, currWindowSize = 1 <= k, windowSum = 1, freqMap = {1:1}
r = 1, l = 0, currWindowSize = 2 <= k, windowSum = 6, freqMap = {1:1}{5:1}
r = 2, l = 0, currWindowSize = 3 <= k, windowSum = 10, freqMap = {1:1}{5:1}{4:1}
r = 3, l = 0, currWindowSize = 4 > k, windowSum = 10-1+2=11 ,l = 1 , freqMap = {5:1}{4:1}{2:1}


*/