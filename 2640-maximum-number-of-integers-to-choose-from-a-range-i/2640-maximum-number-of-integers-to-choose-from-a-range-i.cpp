class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        // Create a HashSet to store all banned numbers for quick lookup.
        unordered_set<int> setBanned(banned.begin(), banned.end());

        int count = 0;
        // Iterate through numbers from 1 to n.
        for(int i = 1; i <= n; i++){
            // Skip the number if it is in the banned set.
            if(setBanned.count(i)){
                continue;
            }
            // If adding the current number exceeds maxSum, return the count.
            if(maxSum - i < 0){
                return count;
            }

            // Deduct the current number from maxSum.
            maxSum = maxSum-i;
            // Increment the count since this number is included.
            count++;
        }
        // Return the total count of numbers included.
        return count;
    }
};