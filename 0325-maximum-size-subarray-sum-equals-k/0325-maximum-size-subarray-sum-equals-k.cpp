class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);  
        cin.tie(NULL);
        
        int n = nums.size();
        int maxLength = 0;
        unordered_map<long long,int> mp;
        long long preSum = 0;

        for(int i = 0; i < n; i++){
            //Accumulate arr[i] to prefix_sum.
            preSum += nums[i];

            //If prefix_sum == k, update maxLen = i+1.
            if(preSum == k){
                maxLength = i+1;
            }

            //Check whether prefix_sum is present in the hash table or not.
            else if(mp.find(preSum - k) != mp.end())
            {
                //update the maxLength if we find previouus (preSum - k) in map
                maxLength = max(maxLength, i - mp[preSum-k]);
            }

            //Update the map if (preSum - k) is not in the map
            if(mp.find(preSum) == mp.end()){
                mp[preSum] = i;
            }
        }

        return maxLength;
    }
};

/*

arr :    -2, -1, 2, 1
preSum : -2, -3, -1,0

map : k = preSum ,v= (index)

_K_|_V__
-2 | 0
-3 | 1
-1 | 2
 0 | 3
_______

This indicates that there is a valid subarray from index 1 to index 2 (which contains [-1, 2]) that sums up to k=1.

So,  maxLength=max(maxLength,i−mp[preSum−k]) equation tells that, i is current end point(end index) and mp[preSum−k] is the start point(start index) where previously we have found the element so as we 
have again game accross the same element at i, therefor end - start (2-0) = 2, so all element between makes no diffrence as we again found the element by (preSum - k)=(-1-1) and k is 1 so nums[i]-nums[i-1] as (2-1) must be equal to 1, 








The code uses the concept of prefix sums to efficiently find subarrays that sum to k:

1> Prefix Sum Definition:

- A prefix sum at index i is the sum of all elements from the start of the array up to index i.
- For example, the prefix sum for index i = 2 is the sum of the elements nums[0] + nums[1] + nums[2].
2> Key Idea:

- If the sum of the subarray from index j+1 to index i is equal to k, then the difference between the prefix sum at index i and the prefix sum at index j must be exactly k. In mathematical terms:
    Sum of subarray from (\U0001d457+1) to \U0001d456 =prefixSum(i) − prefixSum(j) = k

- Therefore, to check if a valid subarray exists, the code looks for prefixSum_i - k in the map (which stores previous prefix sums and their indices).


Example:
Consider the array nums = [-2, -1, 2, 1] and k = 1.

Step 1: Initialize variables:

    preSum = 0: This variable accumulates the prefix sum.
    maxLength = 0: This variable stores the length of the longest subarray that sums to k.
    mp: This is a hash map (unordered_map) that stores the first occurrence of each prefix sum and  its corresponding index.

Step 2: Iterate through the array:

At index i = 0, nums[0] = -2:

    Update preSum:preSum=preSum+nums[0]=0+(−2)=−2

    Since preSum != k and preSum - k = -2 - 1 = -3 is not found in the map, we store preSum = -2 in mp with index 0.
    mp after this step: {-2: 0}.
    
    
At index i = 1, nums[1] = -1:

    - Update preSum:preSum=preSum+nums[1]=−2+(−1)=−3
    - Since preSum != k and preSum - k = -3 - 1 = -4 is not found in the map, we store preSum = -3 in mp with index 1.
    - mp after this step: {-2: 0, -3: 1}.

At index i = 2, nums[2] = 2:

    - Update preSum: preSum=preSum+nums[2]=−3+2=−1
    - Now, check if preSum - k = -1 - 1 = -2 exists in the map. It does, and the index for preSum - k = -2 is 0. This means there is a valid subarray from index 1 to 2 (because 0 + 1 = 1 is the start index): 
            Length of subarray=i−mp[preSum−k]=2−0=2

    - Update maxLength = 2 because this subarray's length is greater than the current maxLength.
    - Store preSum = -1 in mp with index 2.
    - mp after this step: {-2: 0, -3: 1, -1: 2}.

At index i = 3, nums[3] = 1:

    - Update preSum:preSum=preSum+nums[3]=−1+1=0

    - Now, check if preSum - k = 0 - 1 = -1 exists in the map. It does, and the index for preSum - k = -1 is 2. This means there is a valid subarray from index 3 to 3 (but its length is 1):
        - Length of subarray=i−mp[preSum−k]=3−2=1
    - The maxLength remains 2 as this subarray's length is shorter than the current maxLength.
    - Store preSum = 0 in mp with index 3.
    - mp after this step: {-2: 0, -3: 1, -1: 2, 0: 3}

Key Explanation:
- The equation maxLength = max(maxLength, i - mp[preSum - k]) essentially checks if a valid subarray exists whose sum is k. Here:
    - i is the current endpoint (end index) of the subarray.
    - mp[preSum - k] gives the starting point (start index) of the subarray.
    - The difference i - mp[preSum - k] gives the length of the subarray.

In this specific case, we found that the subarray from index 1 to index 2 ([-1, 2]) has a sum equal to k = 1 and its length is 2. Hence, maxLength is updated to 2.

*/