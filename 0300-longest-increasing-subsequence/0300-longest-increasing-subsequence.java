
class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] LIS = new int[n];

        LIS[0] = 1;
        for(int i = 1; i < n; i++){
            LIS[i] = 1;
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    int currLIS = LIS[j]+1;
                    if(currLIS > LIS[i])
                    {
                        LIS[i] = currLIS;
                    }
                    //LIS[i] = Math.max(LIS[i], LIS[j]+1);
                }
            }
        }

        int ans = LIS[0];

        for(int i = 0; i < n; i++){
            ans = Math.max(ans,LIS[i]);
        }

        return ans;
    }
}



/*
class Solution {
    public int lengthOfLIS(int[] nums) {
        int size = nums.length;
        // we created a table here
        int[][] dp = new int[size + 1][size + 1];

        for (int curr = size - 1; curr > -1; curr--) {
            for (int prev = curr - 1; prev > -2; prev--) {
                int length = dp[curr + 1][prev + 1];

                // if 'prev' is negative or previous value is less than the next value we will take it
                if (prev < 0 || nums[prev] < nums[curr]) {
                    length = Math.max(length, 1 + dp[curr + 1][curr + 1]);
                }
                dp[curr][prev + 1] = length;
            }
        }
        return dp[0][0];
    }
}
*/



/*

class Solution {
    private static int lisLengthRec(int[] nums, int curr, int prev) {
        // base case
        // if 'curr' reaches the end of the array, return 0
        if (curr == nums.length) {
            return 0;
        }

        // solve the first subproblem
        // calculate the LIS length from 'curr+1', skipping the current element
        int length = lisLengthRec(nums, curr + 1, prev); 

        // solve the second subproblem
        // if the current element is greater than the previous one in the subsequence
        if (prev < 0 || nums[prev] < nums[curr]) 
        {
            // calculate the LIS length from 'curr+1', including the current element
            length = Math.max(length, 1 + lisLengthRec(nums, curr + 1, curr));
        }
        return length;
    }

    public int lengthOfLIS(int[] nums) {
        return lisLengthRec(nums, 0, -1);
    }
}

*/


// class Solution {
//     public int lengthOfLIS(int[] nums) {
//         int n = nums.length;
//         int[] dp = new int[n+1];
//         Arrays.fill(dp,1);

//         for(int i = 1; i < n; i++)
//         {
//             for(int j = 0; j < i; j++){
//                 if(nums[i] > nums[j])
//                 {
//                     dp[i] = Math.max(dp[i], dp[j]+1);
//                 }
//             }
//         }

//         int longest = 0;
//         for(int x : dp)
//         {
//             longest = Math.max(longest, x);
//         }

//         return longest; 
//     }
// }

