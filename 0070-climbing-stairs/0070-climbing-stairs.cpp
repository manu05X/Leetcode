class Solution {
public:
    int climbStairs(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(n == 1){
            return 1;
        }
         // Initialize variables to store previous two results
        int prevStep = 0; // Corresponds to the number of ways to climb to the previous step
        int currentStep = 1; // Corresponds to the number of ways to climb to the current step
      
        // Loop through the number of stairs to calculate the number of ways
        for (int i = 0; i < n; ++i) {
            // Calculate the number of ways to climb to the next step
            int nextStep = prevStep + currentStep; // Sum of the previous two results
          
            // Update variables for the next iteration
            prevStep = currentStep; // The current step becomes the previous step for the next iteration
            currentStep = nextStep; // The calculated next step becomes the current step for the next iteration
        }
      
        // Return the number of ways to climb to the top step
        return currentStep;
    }
};