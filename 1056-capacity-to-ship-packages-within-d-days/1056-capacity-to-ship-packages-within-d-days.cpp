class Solution {
public:
    bool canShip(vector<int>& weights, int capacity, int days) {
        int requiredDays = 1, currentLoad = 0;
        
        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                requiredDays++;  // Start a new day
                currentLoad = 0;
            }
            currentLoad += weight;
        }
        
        return requiredDays <= days;  // Check if we can fit within days
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (canShip(weights, mid, days)) {
                high = mid;  // Try reducing capacity
            } else {
                low = mid + 1;  // Increase capacity
            }
        }
        
        return low;  // Minimum valid capacity
    }
};
