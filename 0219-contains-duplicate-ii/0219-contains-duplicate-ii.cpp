class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        unordered_map<int,int> mp;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            if(mp.count(nums[i]))
            {
                //map.count returns 1 if the element with key K is present in the map container. It returns 0 if the element with key K is not present in the container.


                if(abs(i-mp[nums[i]]) <= k)
                    return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};