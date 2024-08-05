class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = temperatures.size(); // Number of days based on the temperature list
        vector<int> daysToWait(n); // Initialize the answer array with the same size as temperatures
        stack<int> indexStack; // Stack to keep track of temperatures indices

        // Iterate over each day in temperatures
        for (int i = 0; i < n; ++i) {
            // Check if the current day's temperature is higher than the temperature at the 
            // top of the stack (which represents the last unprocessed day's temperature)
            while (!indexStack.empty() && temperatures[indexStack.top()] < temperatures[i]) {
                int previousDayIndex = indexStack.top(); // Get the index of the day with the lower temperature
                daysToWait[previousDayIndex] = i - previousDayIndex; // Calculate the days to wait
                indexStack.pop(); // Remove that day from the stack since it's now processed
            }
          
            // Always push the current day's index to the stack to process later
            indexStack.push(i);
        }
      
        // The stack will automatically contain 0s where there is no warmer temperature in the future
        return daysToWait;
    }
};