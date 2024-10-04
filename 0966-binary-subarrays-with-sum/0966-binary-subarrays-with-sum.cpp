class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();

        unordered_map<int,int> preSum_freq_map;
        int totalCount = 0;
        int currSum = 0;

        for(int i = 0; i < n; i++)
        {
            currSum += nums[i];
            if(currSum == goal)
            {
                totalCount++;
            }

            if(preSum_freq_map.find(currSum-goal) != preSum_freq_map.end())
            {
                totalCount += preSum_freq_map[currSum-goal];
            }

            preSum_freq_map[currSum]++;
        }
        return totalCount;
    }
};


/*

Key Concepts:
1. Prefix Sum (currSum):
    - This keeps track of the cumulative sum of elements as we iterate through the array.

2. Prefix Sum Frequency Map (preSum_freq_map):
This map stores the frequency of each prefix sum encountered so far. It helps in checking how many previous subarrays have contributed to the target sum.

Example:
Input: nums = [1, 0, 1, 0, 1]
Goal: goal = 2

Explanation:
Variables Initialization:
n = 5 (length of the array).
preSum_freq_map: This is an empty unordered map that will store the frequency of each prefix sum encountered during the iteration.
totalCount = 0: This keeps track of how many subarrays have been found that sum to goal.
currSum = 0: This is used to accumulate the running prefix sum as we iterate through the array.



Iteration through the array:
1. Index 0:

    - nums[0] = 1
    - Update currSum: currSum=0+1=1

    - Check if currSum == goal. Since 1 != 2, no match is found yet.
    - Check if (currSum - goal) exists in preSum_freq_map:1−2=−1
            Since -1 is not in the map, we move on.
    - Update preSum_freq_map with currSum = 1: preSum_freq_map={1:1}

2. Index 1:

    - nums[1] = 0
    - Update currSum: currSum=1+0=1
    - Check if currSum == goal. Since 1 != 2, no match is found.
    - Check if (currSum - goal) exists in preSum_freq_map:1−2=−1
            Still, -1 is not in the map.
    - Update preSum_freq_map with currSum = 1: preSum_freq_map ={1:2}

3. Index 2:

    - nums[2] = 1
    - Update currSum: currSum=1+1=2
    - Check if currSum == goal. Now, 2 == 2, so we have found one subarray [1, 0, 1] that sums to goal. Increment totalCount by 1: totalCount=1
    - Check if (currSum - goal) exists in preSum_freq_map: 2−2=0
        0 is not in the map, so no additional subarrays are counted.
    - Update preSum_freq_map with currSum = 2: preSum_freq_map={1:2,2:1}


4. Index 3:

    - nums[3] = 0
    - Update currSum: currSum=2+0=2
    - Check if currSum == goal. Since 2 == 2, we have found another subarray [1, 0, 1, 0] that sums to goal. Increment totalCount by 1: totalCount=2
    - Check if (currSum - goal) exists in preSum_freq_map:2−2=0
        Still, 0 is not in the map.
    - Update preSum_freq_map with currSum = 2: preSum_freq_map={1:2,2:2}



Index 4:

    - nums[4] = 1
    - Update currSum: currSum=2+1=3
    - Check if currSum == goal. Since 3 != 2, no match is found here.
    - Check if (currSum - goal) exists in preSum_freq_map:3−2=1
            1 exists in the map with frequency 2, meaning there are two previous subarrays (from earlier indices) that, when combined with the current index, will form new subarrays that sum to goal. These subarrays are [0, 1] (from index 1 to 4) and [1, 0, 1] (from index 2 to 4).
    - Increment totalCount by the frequency of 1 in preSum_freq_map (which is 2):totalCount=2+2=4
    - Update preSum_freq_map with currSum = 3: preSum_freq_map={1:2,2:2,3:1}



Final Result:
After iterating through the entire array, the total number of subarrays whose sum is goal = 2 is 4. The four subarrays are:

[1, 0, 1] (from index 0 to 2)
[1, 0, 1, 0] (from index 0 to 3)
[0, 1] (from index 1 to 4)
[1, 0, 1] (from index 2 to 4)
The function returns 4.



*/