class Solution {
private:
    // Helper function to count subarrays with at most k distinct integers
    int atMostKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // Frequency map to track counts of integers
        int left = 0; // Left pointer of the window
        int count = 0; // Count of valid subarrays

        // Iterate through the array with the right pointer
        for (int right = 0; right < nums.size(); right++) {
            // Add the current element to the frequency map
            freq[nums[right]]++;

            // If the number of distinct integers exceeds k, shrink the window
            while (freq.size() > k) {
                freq[nums[left]]--; // Decrement the count of the left element
                if (freq[nums[left]] == 0) {
                    freq.erase(nums[left]); // Remove the element if its count becomes 0
                }
                left++; // Move the left pointer
            }

            // Count the number of valid subarrays ending at the current right pointer
            count += (right - left + 1);
        }

        return count;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Number of subarrays with at most k distinct integers
        int atMostK = atMostKDistinct(nums, k);
        // Number of subarrays with at most k-1 distinct integers
        int atMostKMinus1 = atMostKDistinct(nums, k - 1);

        // Number of subarrays with exactly k distinct integers
        return atMostK - atMostKMinus1;
    }
};


/*
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Helper function to count subarrays with at most k distinct integers
        auto atMostKDistinct = [&](int k) -> int {
            unordered_map<int, int> freq; // Frequency map to track counts of integers
            int left = 0; // Left pointer of the window
            int count = 0; // Count of valid subarrays

            // Iterate through the array with the right pointer
            for (int right = 0; right < nums.size(); right++) {
                // Add the current element to the frequency map
                freq[nums[right]]++;

                // If the number of distinct integers exceeds k, shrink the window
                while (freq.size() > k) {
                    freq[nums[left]]--; // Decrement the count of the left element
                    if (freq[nums[left]] == 0) {
                        freq.erase(nums[left]); // Remove the element if its count becomes 0
                    }
                    left++; // Move the left pointer
                }

                // Count the number of valid subarrays ending at the current right pointer
                count += (right - left + 1);
            }

            return count;
        };

        // Number of subarrays with at most k distinct integers
        int atMostK = atMostKDistinct(k);
        // Number of subarrays with at most k-1 distinct integers
        int atMostKMinus1 = atMostKDistinct(k - 1);

        // Number of subarrays with exactly k distinct integers
        return atMostK - atMostKMinus1;
    }
};
*/