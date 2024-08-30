class Solution {
public:
    int deleteAndEarn(vector<int>& numbers) {
        // We create vals with size enough to cover all potential
        // input numbers, initializing with 0s. This will store the cumulative values.
        vector<int> cumulativeValues(10001, 0);
      
        // Populate cumulativeValues so that each index's value is the sum
        // of all the occurrences of that number in the numbers vector.
        for (int num : numbers) {
            cumulativeValues[num] += num;
        }
      
        // Now we use our rob function to find the maximum amount we can earn
        // following the delete and earn rule.
        return rob(cumulativeValues);
    }

    // The rob function uses dynamic programming to find the maximum earnable amount.
    int rob(vector<int>& values) {
        // Initialize the two variables to keep track of two states:
        // prevMax: the maximum amount we can get from [0...i-2]
        // currentMax: the maximum amount we can get from [0...i-1]
        int prevMax = 0, currentMax = values[0];

        for (int i = 1; i < values.size(); ++i) {
            // Calculate the new max amount that can be earned
            // including the current number or by excluding it.
            // c decides whether to take the current number or not.
            int tempMax = max(values[i] + prevMax, currentMax);

            // Move currentMax to prevMax for the next iteration, and
            // update currentMax to the newly calculated tempMax.
            prevMax = currentMax;
            currentMax = tempMax;
        }

        // At the end, currentMax will contain the maximum amount that
        // can be earned by either taking or skipping each number.
        return currentMax;
    }
};
/*
[2,2,3,3,3,4]

2->4
3->9
4->4
maxNumber = 9;

*/