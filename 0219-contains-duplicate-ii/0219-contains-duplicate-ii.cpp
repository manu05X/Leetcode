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
            //map.count returns 1 if the element with key K is present in the map container. It returns 0 if the element with key K is not present in the container.

            if(mp.count(nums[i]))
            {
                //last index of k in map
                int kIndex = mp[nums[i]];
                // abs diffrence curr idex and kIndex
                int diff = abs(i-kIndex);

                if(diff <= k)
                    return true;
            }
            // inserting element in map
            mp[nums[i]] = i;
        }
        return false;
    }
};