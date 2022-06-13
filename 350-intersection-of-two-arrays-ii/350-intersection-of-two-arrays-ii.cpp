class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp;
        for(auto x:nums2)
            mp[x]++;
        vector<int> ans;
        for(auto x: nums1)
        {
            if(mp.count(x) && mp[x] != 0)
            {
                ans.push_back(x);
                mp[x]--;
            }
        }
        return ans;
    }
};