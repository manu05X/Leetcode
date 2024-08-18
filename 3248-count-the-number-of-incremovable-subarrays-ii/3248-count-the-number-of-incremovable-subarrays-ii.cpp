class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        long long ans=0;
        int n=nums.size(), i=0, j=n-1;
        
        for(; j && nums[j]>nums[j-1]; --j) {}
        for(; i<n; ++i) {
            j=max(j, i+1);
            ans+=n-j+1;
            for(; j<n && nums[j]<=nums[i]; ++j) {}
            if(i && nums[i]<=nums[i-1])
                break;
        }
        return ans;
    }
};