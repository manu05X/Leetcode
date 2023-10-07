class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int curEnd = 0, curFar = 0;

        for(int i = 0; i < n-1; i++){
            int reachableIndex = i+nums[i];
            // update the curFar
            curFar = max(curFar, reachableIndex);

            // If we finish the starting range of this jump,
            // Move on to the starting range of the next jump.
            if(i == curEnd){
                ans++;
                curEnd = curFar;
            }
        }

        return ans;
    }
};