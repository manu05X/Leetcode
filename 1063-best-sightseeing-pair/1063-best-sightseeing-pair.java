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
Dry Run of the Code:
Input:
values = [8, 1, 5, 2, 6]

Iterations:
Initialization:
n = 5
maxScore = Integer.MIN_VALUE
maxLeftScore = 8 (Initial left score is values[0])
Iteration 1 (i = 1):
Current values[1] = 1
currRightScore = values[1] - 1 = 1 - 1 = 0
Update maxScore:
maxScore = Math.max(Integer.MIN_VALUE, 0 + 8) = 8
Update maxLeftScore:
currLeftScore = values[1] + 1 = 1 + 1 = 2
maxLeftScore = Math.max(8, 2) = 8
Iteration 2 (i = 2):
Current values[2] = 5
currRightScore = values[2] - 2 = 5 - 2 = 3
Update maxScore:
maxScore = Math.max(8, 3 + 8) = 11
Update maxLeftScore:
currLeftScore = values[2] + 2 = 5 + 2 = 7
maxLeftScore = Math.max(8, 7) = 8
Iteration 3 (i = 3):
Current values[3] = 2
currRightScore = values[3] - 3 = 2 - 3 = -1
Update maxScore:
maxScore = Math.max(11, -1 + 8) = 11
Update maxLeftScore:
currLeftScore = values[3] + 3 = 2 + 3 = 5
maxLeftScore = Math.max(8, 5) = 8
Iteration 4 (i = 4):
Current values[4] = 6
currRightScore = values[4] - 4 = 6 - 4 = 2
Update maxScore:
maxScore = Math.max(11, 2 + 8) = 13
Update maxLeftScore:
currLeftScore = values[4] + 4 = 6 + 4 = 10
maxLeftScore = Math.max(8, 10) = 10
Final Output:
maxScore = 13

*/



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