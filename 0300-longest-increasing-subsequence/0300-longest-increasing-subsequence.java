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