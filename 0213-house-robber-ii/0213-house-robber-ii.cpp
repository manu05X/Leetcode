class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n < 2) {
            return nums[0];
        }

        vector<int> skipLastHouse(n - 1);
        vector<int> skipFirstHouse(n - 1);

        for (int i = 0; i < n - 1; i++) {
            skipLastHouse[i] = nums[i];
            skipFirstHouse[i] = nums[i + 1];
        }

        int lootskipLast = robStright(skipLastHouse);
        int lootskipFirst = robStright(skipFirstHouse);

        return max(lootskipFirst, lootskipLast);
    }

    int robStright(vector<int>& nums) {
        int n = nums.size();

        if (n < 2) {
            return nums[0];
        }

        vector<int> ans(n);

        ans[0] = nums[0];
        ans[1] = max(nums[1], nums[0]);

        for (int i = 2; i < n; i++) {
            ans[i] = max(ans[i - 1], ans[i - 2] + nums[i]);
        }

        return ans[n - 1];
    }
};