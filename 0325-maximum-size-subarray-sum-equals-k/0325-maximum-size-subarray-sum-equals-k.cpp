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