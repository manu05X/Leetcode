class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        // Length of the array
        int n = values.length;

        // Variable to store the maximum score of sightseeing pair
        int maxScore = Integer.MIN_VALUE;

        // Variable to store the maximum value of `values[i] + i` for the left side of the pair
        int maxLeftScore = values[0]; // Initially set to the first element's score

        // Traverse the array starting from the second element
        for (int i = 1; i < n; i++) {
            // Calculate the current "right" score: `values[j] - j`
            int currRightScore = values[i] - i;

            // Update the maximum score using the current "right" and "left" scores
            maxScore = Math.max(maxScore, currRightScore + maxLeftScore);

            // Update the maximum "left" score: `values[i] + i` for future pairs
            int currLeftScore = values[i] + i;
            maxLeftScore = Math.max(maxLeftScore, currLeftScore);
        }

        // Return the maximum score
        return maxScore;
    }
}



/*
class Solution {
    public int maxScoreSightseeingPair(int[] values) {
        int n = values.length;
        int ans = Integer.MIN_VALUE;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int temp = values[i]+values[j] + i -j;
                ans = Math.max(temp, ans);
            }
        }

        return ans;
    }
}

 */