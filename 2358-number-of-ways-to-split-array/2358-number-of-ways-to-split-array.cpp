class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long leftSum = 0, totalSum = 0;
        for(int i = 0; i < n; i++){
            totalSum += nums[i];
        }


        int count = 0;
        for(int i =0; i < n-1; i++){
            leftSum += nums[i];

            long rightSum = totalSum-leftSum;

            if(leftSum >= rightSum){
                count++;
            }
        }

        return count;
    }
};

/*
10 + 4 -8 +7

10, 14, 6, 13

*/