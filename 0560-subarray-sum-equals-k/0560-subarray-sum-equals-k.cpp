class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0; // Variable to store the number of subarrays that sum to k.
        int sum = 0; // Variable to store the cumulative sum of elements.

        unordered_map<int,int> mp;
        // Base case: there's one way to have a sum of 0 (no elements).
        mp[sum] = 1;
        for(int i = 0; i < n; i++)
        {
            sum += nums[i]; // Update the cumulative sum.
            int diff = sum-k;
            // If cumulativeSum - k i.e diff exists in mp, then a subarray ending at current index has a sum of k. We add the count of those occurrences to answer.
            if(mp.find(diff) != mp.end())
            {
                count += mp[diff];
            }
            // We then increment the count of cumulativeSum in our frequency map.
            mp[sum]++;
        }

        return count;
    }
};