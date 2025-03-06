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