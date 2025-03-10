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


/*
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

/*
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
*/
