// Method 4
class Solution {
    public int climbStairs(int n) {
        // Base cases
        if(n == 1 || n == 0){
            return 1;
        }
        // Initialize variables for (n-2) and (n-1)
        int prevStep = 1; // ways to climb 0 steps
        int currStep = 1; // ways to climb 1 step
        
        for(int i = 2; i <= n; i++){
            int nextStep = currStep + prevStep; // ways to climb i steps
            
            prevStep = currStep; // update the prevStep to currStep
            currStep = nextStep; // update the currStep to nextStep
        }
        
        return currStep;
    }
}

/*
// Method 3
class Solution {
    public int climbStairs(int n) {
        // Base Conditions
        if(n < 0) return 0;
        if(n == 0)
        { 
            return 1;
        }

        // Initialize lookup table
        int[] lookupArr = new int[n+1];
        for(int i = 0; i < n+1; i++){
            lookupArr[i] = 0;
        }

         // Setting the first two values
        lookupArr[0] = 1;
        lookupArr[1] = 1;

        for(int i = 2; i <= n; i++){
            // Fill up the table by summing up previous two values
            lookupArr[i] = lookupArr[i-1] + lookupArr[i-2];
        }

        return lookupArr[n];
    }
}

*/

/*
// Method 2
class Solution {
    public int climbStairsRecur(int n, int[] lookupArr){

        //Negative staircases i.e., invalid input
        if(n < 0) 
            return 0;
        // if 0 staircase
        else if(n == 0)
        { 
            return 1;
        }
        //If already present in the table
        else if(lookupArr[n] > -1){
            return lookupArr[n];
        }
        else   // Check each possible combination i.e The total number of ways that the child can hop the stairs
        {
            lookupArr[n] = climbStairsRecur(n-1, lookupArr) + climbStairsRecur(n-2, lookupArr);
        }
        return lookupArr[n];
    }

    public int climbStairs(int n) {
        int[] lookupArr = new int[n+1];
        for(int i = 0; i < n+1; i++){
            lookupArr[i] = -1;
        }

        return climbStairsRecur(n, lookupArr);
    }
}

*/

/*
// Method 1
class Solution {
    public int climbStairs(int n) {
        // Base Conditions
        if(n < 0) return 0;
        else if(n == 0)
        { 
            return 1;
        }
        else   // Check each possible combination i.e The total number of ways that the child can hop the stairs
        {
            return climbStairs(n-1) + climbStairs(n-2);
        }
    }
}
*/


