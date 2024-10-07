class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++){
            mp[nums[i]]++;
        }

        int ans = -1;
        for(auto x : mp){
            if(x.second == 1){
                ans = max(x.first, ans);
            }
        }

        return ans;
    }
};