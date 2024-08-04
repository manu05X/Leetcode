class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int l, int r) {
        vector<int> sums;

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int curr = nums[j];
                if(j != i){
                    curr += sums.back();
                }
                sums.push_back(curr);
            }
        }

        sort(sums.begin(), sums.end());

        // for(int x : sums){
        //     cout<< x << " ";
        // }

        int ans = 0, mod = 1e9 + 7;;
        for(int i = l-1; i < r; i++){
            ans = (ans+sums[i])%mod;
        }

        return ans;
    }
};