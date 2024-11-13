class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i++){
            nums[i] = nums[i-1] + nums[i];
        }

        vector<int> ans;
        for(int x : queries){
            int index = upper_bound(nums.begin(), nums.end(), x) - nums.begin();

            ans.push_back(index);
        }

        return ans;
    }
};
