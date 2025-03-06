class Solution {
    public int rob(int[] nums) {
        int n = nums.length;

        // Base cases
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Initialize variables for (i-1) and (i-2)
        int prev1 = nums[0]; // maximum money up to the first house
        int prev2 = 0;       // maximum money up to the "house before the first house"

        // Iterate from the second house to the last house
        for (int i = 1; i < n; i++) {
            int current = Math.max(prev1, prev2 + nums[i]); // maximum money up to house i
            prev2 = prev1; // update prev2 to prev1
            prev1 = current; // update prev1 to current
        }

        // Return the maximum money up to the last house
        return prev1;
    }
}


/*
class Solution {
    public int rob(int[] nums) {
        int n = nums.length;

        int prev_rob = 0; 
        int max_rob = 0;

        for(int i = 0; i < n; i++){
            int currRob = Math.max(prev_rob + nums[i], max_rob);
            prev_rob = max_rob;
            max_rob = currRob;
        }

        return max_rob;
    }
}
*/

/*
Approach
Input: nums = [2,7,9,3,1]
First of all, let's think about [2, 7].

There are security systems, so we cannot break both houses because they are adjacent houses. We need to choose one of them to get money.

It's obvious that if we break index 0 house, maximum money should be 2 and if we break index 1 house, maximum money should 7.

[2,7,9,3,1]
[2,7,0,0,0] (maximum money you can get at each position)
Let's think about index 2 house.

     i
[2,7,9,3,1]
[2,7,0,0,0] (maximum money you can get at each position)
If we break index 2 house, we will get 11 money.

Why?

That's because we can also break index 0 house, because index 0 house and index 2 house are not adjacent houses, so security systems will not go off.

There is one more case where you don't break index 2 house. In that case, you can break index 1 house to get money, but you can't break index 0 house because index 0 house and index 1 house are adjacent houses.

From the example, we can create very important formula.

⭐️ Points

Every time we compare two cases.

maximum money at previous house 
vs
maximum money at current house + i - 2 house
At index 2, we can calculate like this

     i
[2,7,9,3,1]
[2,7,0,0,0] (maximum money you can get at each position)

max(7, 9 + 2)
= 11

     i
[2,7,9,3,1]
[2,7,11,0,0] (maximum money you can get at each position)
Let's move on.

       i
[2,7,9,3,1]
[2,7,11,0,0] (maximum money you can get at each position)
In that case, if you break current house, we will get money from index 1 and index 3

index 1 and index 3
= 7 + 3
= 10
If you break previous house, you will get 11, not 9.

Why?

That's the same reason. You can also break index 0 in that case, so maximum money should be.

index 0 + index 2
= 2 + 9
= 11
In the end,

max(10, 11)
= 11

       i
[2,7,9,3,1]
[2,7,11,11,0] (maximum money you can get at each position)
I'll speed up.

         i
[2,7,9,3,1]
[2,7,11,11,0] (maximum money you can get at each position)
In that case,

max(index 3, index 4 + index 2 + index 0)
= max(11, 1 + 11)
= 12

The first 11 is maximum money from [2,7,9,3].
The second 11 comes from index 2(= 9) + index 0(= 2).
So, 1 + 11 means you break index 0, index 2 and index 4 houses.
         i
[2,7,9,3,1]
[2,7,11,11,12] (maximum money you can get at each position)
You can return the last number.

return 12

*/