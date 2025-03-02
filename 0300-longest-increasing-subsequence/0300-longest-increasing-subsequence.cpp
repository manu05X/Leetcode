class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array
        vector<int> dp(n, 1); // Initialize DP array with all values as 1
        
        // Iterate over each element in nums
        for(int i = 0; i < n; i++){
            // Check all previous elements before index i
            for(int j = 0; j < i; j++){
                // If nums[j] is smaller than nums[i], it can be part of an increasing subsequence
                if(nums[j] < nums[i]){
                    // Update dp[i] to store the maximum length of LIS ending at index i
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int longest = 0; // Variable to store the maximum LIS length
        
        // Find the maximum value in the dp array, which represents the LIS length
        for(int x : dp){
            longest = max(longest, x);
        }

        return longest; // Return the length of the longest increasing subsequence
    }
};


/*
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //vector<int> LIS(n,0);
        int LIS[n];
        fill(LIS, LIS + n, 0); // Initialize all elements of dp to 0
        //Initializes the LIS array by setting the first element to 1, as the LIS of a single element is always 1.
        LIS[0] = 1;

        for(int i = 1; i < n; i++){
            // Initializes the LIS value at the current index to 1, assuming the current element itself forms a subsequence of length 1.
            LIS[i] = 1;
            for(int j = 0; j < i; j++){
                //Checks if the element at index j is less than the element at index i
                if(nums[j] < nums[i]){
                    //Updates the LIS value at index i by taking the maximum between its current value and the LIS value at index j plus 1.
                    LIS[i] = max(LIS[i], LIS[j]+1);
                }
            }
        }
        
        int bestAns = LIS[0];
        for(int i = 1; i < n; i++){
            bestAns = max(bestAns, LIS[i]);
        }
        return bestAns;
    }
};

*/