class Solution {
    public int fib(int n) {
        // Base cases
        if (n == 0) return 0;
        if (n == 1) return 1;

        // Initialize variables for (n-2) and (n-1)
        int prevStep = 0; // F(0)
        int currStep = 1; // F(1)
        
        // Iterate from 2 to n
        for(int i = 2; i <= n; i++){
            int nextStep = currStep + prevStep; // F(i) = F(i-1) + F(i-2)
            
            prevStep = currStep; // update the prevStep to currStep
            currStep = nextStep; // update the currStep to nextStep
        }
        
        return currStep;
    }
}