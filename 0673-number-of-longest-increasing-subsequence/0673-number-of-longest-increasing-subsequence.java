// class Solution {
//     public int findNumberOfLIS(int[] nums) {
//         int n = nums.length;
//         int[] LIS = new int[n];

//         LIS[0] = 1;
//         int maxLength = -1;
//         for(int i = 1; i < n; i++){
//             LIS[i] = 1;
//             for(int j = 0; j < i; j++){
//                 if(nums[j] < nums[i]){
//                     int currLIS = LIS[j]+1;
//                     if(currLIS > LIS[i])
//                     {
//                         LIS[i] = currLIS;
                        
//                     }
//                     //LIS[i] = Math.max(LIS[i], LIS[j]+1);
//                 }
//             }
//             maxLength = Math.max(maxLength,LIS[i]);
//         }

//         int ans = 0;

//         for(int i = 0; i < n; i++){
//             if(maxLength == LIS[i])
//                 ans++;
//         }

//         return ans;
//     }
// }


class Solution {
    public int findNumberOfLIS(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        
        int[] LIS = new int[n]; // Length of LIS ending at each index
        int[] count = new int[n]; // Number of LIS ending at each index
        Arrays.fill(LIS, 1);
        Arrays.fill(count, 1);

        int maxLength = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (LIS[j] + 1 > LIS[i]) {
                        LIS[i] = LIS[j] + 1;
                        count[i] = count[j]; // reset the count
                    } else if (LIS[j] + 1 == LIS[i]) {
                        count[i] += count[j]; // add the count
                    }
                }
            }
            maxLength = Math.max(maxLength, LIS[i]);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (LIS[i] == maxLength) {
                ans += count[i];
            }
        }

        return ans;
    }
}
