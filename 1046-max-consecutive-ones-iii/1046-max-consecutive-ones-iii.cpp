class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         int zeroCount = k; // Number of zero's in the window.
        int longestWindow = 0;

        int l = 0;
        for(int r = 0; r < nums.size(); r++){
            zeroCount -= (nums[r] == 0);
            // Shrink the window until the zero counts come under the limit.
            while(zeroCount < 0){
                zeroCount += (nums[l] == 0);
                l++;
            }

            longestWindow = max(longestWindow, r-l+1);
        }

        return longestWindow;
    }
};