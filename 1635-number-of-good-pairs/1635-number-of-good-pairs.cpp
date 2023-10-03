class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int count = 0;

        for(int x : nums){
            count += mp[x];
            mp[x]++;
        }

        return count;   
    }
};