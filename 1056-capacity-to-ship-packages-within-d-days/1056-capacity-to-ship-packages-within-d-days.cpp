class Solution {
public:
    // Function to check if a given capacity allows shipping within 'days'
    bool canShip(vector<int>& weights, int capacity, int days) {
        int requiredDays = 1, currentLoad = 0;  // Start with 1 day and 0 load
        
        for (int weight : weights) {
            if (currentLoad + weight > capacity) { // If adding this weight exceeds capacity
                requiredDays++;  // Start a new day
                currentLoad = 0;  // Reset current load
            }
            currentLoad += weight;  // Add package to the ship
        }
        
        return requiredDays <= days;  // Return whether it fits in given days
    }
    
    // Binary search to find the minimum required capacity
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end()); // Minimum capacity is max weight
        int high = accumulate(weights.begin(), weights.end(), 0); // Max capacity is sum of weights
        
        while (low < high) {
            int mid = low + (high - low) / 2; // Try mid capacity
            
            if (canShip(weights, mid, days)) {
                high = mid;  // Try reducing capacity
            } else {
                low = mid + 1;  // Increase capacity
            }
        }
        
        return low;  // Minimum valid capacity
    }
};


