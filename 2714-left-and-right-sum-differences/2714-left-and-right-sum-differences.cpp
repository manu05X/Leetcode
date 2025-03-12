class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        // Optimizes input/output operations for faster execution
        ios_base::sync_with_stdio(false);  
        cin.tie(NULL);
        
        int n = nums.size();

        // Arrays to store prefix sum from the left and right
        vector<int> leftSum(n, 0), rightSum(n, 0), ans(n, 0);

        // Initialize first and last elements of prefix sum arrays
        leftSum[0] = nums[0];
        rightSum[n - 1] = nums[n - 1]; 

        // Compute left prefix sum
        for(int i = 1; i < n; i++){
            leftSum[i] = leftSum[i - 1] + nums[i];
            rightSum[n - i - 1] = rightSum[n - i] + nums[n - i - 1]; // Compute right prefix sum
        }

        // Debugging: Print leftSum and rightSum arrays
        // cout << "LeftSum: ";
        // for(int i = 0; i < n; i++){
        //     cout << leftSum[i] << " ";
        // }
        // cout << endl;

        // cout << "RightSum: ";
        // for(int i = 0; i < n; i++){
        //     cout << rightSum[i] << " ";
        // }
        // cout << endl;

        // Compute the absolute difference between left and right prefix sums
        for(int i = 0; i < n; i++){
            ans[i] = abs(leftSum[i] - rightSum[i]);
        }

        return ans; // Return the result array
    }
};


/*

Dry Run Example:
Input: nums = [10, 4, 8, 3]

leftSum:

leftSum[0] = 10
leftSum[1] = 10 + 4 = 14
leftSum[2] = 14 + 8 = 22
leftSum[3] = 22 + 3 = 25
=> leftSum = [10, 14, 22, 25]

rightSum:

rightSum[3] = 3
rightSum[2] = 3 + 8 = 11
rightSum[1] = 11 + 4 = 15
rightSum[0] = 15 + 10 = 25
=> rightSum = [25, 15, 11, 3]

ans:

ans[0] = |10 - 25| = 15
ans[1] = |14 - 15| = 1
ans[2] = |22 - 11| = 11
ans[3] = |25 - 3| = 22

Output: [15, 1, 11, 22]

*/