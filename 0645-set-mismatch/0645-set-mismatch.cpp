class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int dup = -1, missing = 1;
    
    // Iterate through the array
    for (int i = 0; i < nums.size(); i++) {
        int n = nums[i];
        
        // If the number at the absolute value of n minus 1 is negative, we found the duplicate
        if (nums[abs(n) - 1] < 0) {
            dup = abs(n);
        } else {
            // Mark the visited number by negating its value
            nums[abs(n) - 1] *= -1;
        }
    }

    // Iterate through the modified array to find the missing number
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > 0) {
            missing = i + 1;
        }
    }

    // Return the result as a vector
    return {dup, missing};

    }
};

/*

Dry Run
Input:
nums = [1, 2, 2, 4]

Execution:
Initial State: nums = [1, 2, 2, 4], dup = -1, missing = 1

Marking Visited Numbers:

Index (i)	nums[i]	abs(nums[i]) - 1	nums Before Update	Action	nums After Update	dup
0	1	0	[1, 2, 2, 4]	Negate nums[0]	                            [-1, 2, 2, 4]	-1
1	2	1	[-1, 2, 2, 4]	Negate nums[1]	                            [-1, -2, 2, 4]	-1
2	2	1	[-1, -2, 2, 4]	nums[1] < 0, set dup=2	                    [-1, -2, 2, 4]	2
3	4	3	[-1, -2, 2, 4]	Negate nums[3]	                            [-1, -2, 2, -4]	2


Finding Missing Number:
Index (i)	nums[i]	Condition (nums[i] > 0)	Missing
0	            -1	        False	        1
1	            -2	        False	        1
2	            2	        True	        3
3	            -4	        False	        3


Final Result:
dup = 2, missing = 3
Return [2, 3]

Output:
Duplicate: 2, Missing: 3
Result: [2, 3]

*/