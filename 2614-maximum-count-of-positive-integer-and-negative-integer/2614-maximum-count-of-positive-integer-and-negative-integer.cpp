class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int countN = 0;
        int countP = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                countP++;
            } else if(nums[i] < 0){
                countN++;
            } else {
                continue;
            }
        }

        return max(countP, countN);
    }
};