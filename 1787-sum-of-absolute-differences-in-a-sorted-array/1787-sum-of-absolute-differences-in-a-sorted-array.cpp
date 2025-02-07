class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        //[2, 3, 5, 7, 11]
        int n = nums.size();
        vector<int> prefix = {nums[0]};

        for(int i = 1; i < n; i++){
            prefix.push_back(prefix[i-1]+nums[i]);
            //[2, 5, 10, 17, 28]
        }

        vector<int> result;
        for(int i = 0; i < n; i++){
            // left and right sum of curr element
            int leftSum = prefix[i]-nums[i];
            int rightSum = prefix[n-1]-prefix[i];

            // count of element to left and right of curr element
            int leftCount = i;
            int rightCount = n-1-i;

            //difference between nums[i] and each element on the left.
            int leftTotal = leftCount*nums[i] - leftSum;
            //difference between nums[i] and each element on the right.
            int rightTotal = rightSum - rightCount*nums[i];

            result.push_back(leftTotal+rightTotal);
        }
        //[18,15,13,15,27]
        return result;
    }
};
/*
[2, 3, 5, 7, 11]
[2, 5, 10, 17, 28]

i = 0 ,nums[0] = 2
leftSum = 0, rightSum = 28
leftCount = 0, rightCount = 4
LeftTotal = 0, RightTotal = (26 - 4 * 2) = 26 - 8 = 18.
Result = [18]


i = 1, nums[1] = 3
leftSum = 2, rightSum = 26
leftCount = 1, rightCount = 3
Left total: (1 * 3 - 2) = 3 - 2 = 1 , Right total: (23 - 3 * 3) = 23 - 9 = 14
for i = 1 => 1+15
Result = [18, 15]


i = 2, nums[2] = 5
leftSum = 5, rightSum = 18
leftCount = 2, rightCount = 2
Left total: (2 * 5 - 5) = 10 - 5 = 5 , Right total: (18 - 2 * 5) = 18 - 10 = 8
for i = 2 => 5+8
Result = [18, 15, 13]


i=3, nums[3] = 7
leftSum = 10, rightSum = 11
leftCount = 3, rightCount = 1
Left total: (3 * 7 - 10) = 21 - 10 = 11 , Right total: (11 - 1 * 7) = 11 - 7 = 4
for i = 3 => 11 + 4 = 15
Result = [18, 15, 13, 15]

i=4, nums[4] = 11
leftSum = 17, rightSum = 0
leftCount = 4, rightCount = 0.
Left total: (4 * 11 - 17) = 44 - 17 = 27 , Right total: (0 - 0 * 7) = 0 - 0 =0
for i = 3 => 27 + 0 = 27


Result : [18,15,13,15,27]

*/