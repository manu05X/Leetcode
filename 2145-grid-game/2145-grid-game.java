class Solution {
    public long gridGame(int[][] grid) {
        // Calculate the sum of all the elements for the first row
        long firstRowSum = 0;
        for (int num : grid[0]) {
            firstRowSum += num;
        }
        long secondRowSum = 0;
        long minimumSum = Long.MAX_VALUE;
        for (int turnIndex = 0; turnIndex < grid[0].length; ++turnIndex) {
            firstRowSum -= grid[0][turnIndex];
            // Find the minimum maximum value out of firstRowSum and
            // secondRowSum.
            minimumSum = Math.min(
                minimumSum,
                Math.max(firstRowSum, secondRowSum)
            );
            secondRowSum += grid[1][turnIndex];
        }
        return minimumSum;
    }
}

/*
[2,5,4],
[1,5,1]


i = 0
firstRowSum = 11-2 -> 9

minSum = min(minSum, max(10,0)) => min(minSum, 9) => 9
SecondRowSum = 0+1=>1


i = 1
firstRowSum = 9-5 -> 4

minSum = min(minSum, max(4,1)) => min(10, 4) => 4
SecondSum = 1+5 => 6



i = 2
firstRowSum = 4-4 -> 0

minSum = min(minSum, max(0,6)) => min(4, 6) => 4
SecondSum = 1+6 => 7


 */