class Solution {
    public int[] minOperations(String boxes) {
        int n = boxes.length(); // Length of the input string.

        int[] ans = new int[n]; // Array to store the result for each index.

        // Variables to track cumulative moves and balls on the left and right sides.
        int movesLeft = 0, movesRight = 0; 
        int ballsLeft = 0, ballsRight = 0; 

        // Iterate through the string from both directions simultaneously.
        for (int i = 0; i < n; i++) {
            // Update the result for the current index from the left direction.
            ans[i] += movesLeft;

            // Update the number of balls on the left side.
            ballsLeft += Character.getNumericValue(boxes.charAt(i));

            // Update the cumulative moves required for the next index from the left.
            movesLeft += ballsLeft;

            // Calculate the index `j` when iterating from the right direction.
            int j = n - 1 - i;

            // Update the result for the current index from the right direction.
            ans[j] += movesRight;

            // Update the number of balls on the right side.
            ballsRight += Character.getNumericValue(boxes.charAt(j));

            // Update the cumulative moves required for the next index from the right.
            movesRight += ballsRight;
        }

        // Return the resulting array.
        return ans;
    }
}

/*

class Solution {

    public int[] minOperations(String boxes) {
        int[] answer = new int[boxes.length()];
        for (int currentBox = 0; currentBox < boxes.length(); currentBox++) {
            // If the current box contains a ball, calculate the number of moves for every box.
            if (boxes.charAt(currentBox) == '1') {
                for (int newPosition = 0; newPosition < boxes.length();newPosition++) {
                    answer[newPosition] += Math.abs(newPosition - currentBox);
                }
            }
        }
        return answer;
    }
}
 */