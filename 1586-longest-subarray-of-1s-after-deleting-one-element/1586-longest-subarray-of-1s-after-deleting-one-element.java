// class Solution {
//     public int longestSubarray(int[] nums) {
//         int l = 0; 
//         int n = nums.length;
//         int maxLength = 0;
//         int zeroCount = 0;

//         for(int r = 0; r < n; r++)
//         {
//             if(nums[r] == 0){
//                 zeroCount++;
//             }

//             while(zeroCount > 1)
//             {
//                 if(nums[l] == 0){
//                     zeroCount--;
//                 }
//                 l++;
//             }
//             maxLength = Math.max(maxLength, r-l);
//         }

//         return maxLength;
//     }
// }

class Solution {
    public int longestSubarray(int[] nums) {
        int l = 0; 
        int n = nums.length;
        int maxLength = 0;
        int zeroCount = 1;

        for(int r = 0; r < n; r++)
        {
            if(nums[r] == 0){
                zeroCount--;
            }

            while(zeroCount < 0)
            {
                if(nums[l] == 0){
                    zeroCount++;
                }
                l++;
            }
            maxLength = Math.max(maxLength, r-l);
        }

        return maxLength;
    }
}