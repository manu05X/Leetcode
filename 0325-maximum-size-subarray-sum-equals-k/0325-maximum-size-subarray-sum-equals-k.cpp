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

- The prefix sum at any index i is the sum of all elements from the start of the array up to index i.
- If we want to find a subarray that sums to k, we can use the relationship:
    prefix sum[j]−k=prefix sum[i−1]
- This means that if we have a prefix sum at index j and we subtract k, we need to check if this resulting value (let's call it target) has been seen before as a prefix sum.

Using the Hash Map:
- The hash map mp stores previously encountered prefix sums and their respective indices.
- When we check if (preSum - k) exists in mp, we are essentially checking if there is a previous prefix sum that would allow us to conclude that there is a subarray summing to k.

- we check for (preSum - k): -1-1 = -2
- we compute the length:
   - maxLength=max(maxLength,i−mp[preSum−k])= max(0, 2-mp[-2])=max(0,2−0)=2

This indicates that there is a valid subarray from index 1 to index 2 (which contains [-1, 2]) that sums up to k=1.

*/