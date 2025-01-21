class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        //int n = grid.size();
        int m = grid[0].size();

        long long firstRowSum = 0;
        // calculate sum of first row
        for(int i = 0; i < m; i++){
            firstRowSum += grid[0][i];
        }

        long long secondRowSum = 0;
        long long minSum = LONG_MAX;
        for(int i = 0; i < m; i++){
            // sub the curr col elment of first row from firstRowSum
            firstRowSum -= grid[0][i];
            // Find the minimum maximum value out of firstRowSum and secondRowSum.
            // min max sum for second robot
            minSum = min(minSum, max(firstRowSum, secondRowSum));
            // sum of 2nd row sum
            secondRowSum += grid[1][i];
        }

        return minSum;
    }
};


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