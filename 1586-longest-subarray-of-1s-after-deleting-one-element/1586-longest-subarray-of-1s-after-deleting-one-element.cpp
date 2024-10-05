// class Solution {
// public:
//     int longestSubarray(vector<int>& nums) {
//         int zeroCount = 0; // Number of zero's in the window.
//         int longestWindow = 0;

//         int l = 0;
//         for(int r = 0; r < nums.size(); r++){
//             zeroCount += (nums[r] == 0);
//             // Shrink the window until the zero counts come under the limit.
//             while(zeroCount > 1){
//                 zeroCount -= (nums[l] == 0);
//                 l++;
//             }

//             longestWindow = max(longestWindow, r-l);
//         }

//         return longestWindow;
//     }
// };

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount = 1; // Number of zero's to delete.
        int longestWindow = 0;

        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            zeroCount -= (nums[r] == 0);
            // Shrink the window until the zero counts come under the limit.
            while(zeroCount < 0){
                zeroCount += (nums[l] == 0);
                l++;
            }

            longestWindow = max(longestWindow, r-l);
        }

        return longestWindow;
    }
};