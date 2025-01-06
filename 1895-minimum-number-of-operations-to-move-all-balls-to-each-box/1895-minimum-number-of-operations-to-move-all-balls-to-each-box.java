class Solution {

    public int[] minOperations(String boxes) {
        int n = boxes.length();

        int[] ans = new int[n];

        int movesLeft = 0, movesRight = 0;
        int ballsLeft = 0, ballsRight = 0;
        for(int i = 0; i < n; i++){
            ans[i] += movesLeft;
            ballsLeft += Character.getNumericValue(boxes.charAt(i));
            movesLeft += ballsLeft;

            int j = n-1-i;
             ans[j] += movesRight;
            ballsRight += Character.getNumericValue(boxes.charAt(j));
            movesRight += ballsRight;
        }

        return ans;
    }
}