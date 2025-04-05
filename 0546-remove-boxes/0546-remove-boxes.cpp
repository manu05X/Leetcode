class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        int dp[100][100][100] = {0}; // DP table initialized to 0
        return helper(boxes, 0, n - 1, 0, dp);
    }
    
    int helper(vector<int>& boxes, int i, int j, int k, int dp[100][100][100]) {
        if (i > j) return 0;
        
        // If already computed, return the stored value
        if (dp[i][j][k] > 0) return dp[i][j][k];
        
        // Original i and k for the case where we don't merge with previous same colors
        int original_i = i, original_k = k;
        
        // Merge with previous same colors if possible
        while (i < j && boxes[i] == boxes[i+1]) {
            i++;
            k++;
        }
        
        // Option 1: Remove the current group of boxes
        int res = (k+1)*(k+1) + helper(boxes, i+1, j, 0, dp);
        
        // Option 2: Try to merge with other boxes of same color later in the sequence
        for (int m = i+1; m <= j; m++) {
            if (boxes[i] == boxes[m]) {
                res = max(res, helper(boxes, i+1, m-1, 0, dp) + helper(boxes, m, j, k+1, dp));
            }
        }
        
        // Store the result in DP table
        dp[original_i][j][original_k] = res;
        return res;
    }
};



/*
class Solution {
public:

    int removeBoxesHelper(vector<int>& boxes) {
        if (boxes.empty()) return 0;
        
        int max_points = 0;
        int n = boxes.size();
        
        for (int i = 0; i < n; ) {
            int current_color = boxes[i];
            int j = i;
            
            // Find all consecutive boxes of same color
            while (j < n && boxes[j] == current_color) {
                j++;
            }
            
            int k = j - i; // Number of boxes to remove
            
            // Create new vector without these boxes
            vector<int> new_boxes(boxes.begin(), boxes.begin() + i);
            new_boxes.insert(new_boxes.end(), boxes.begin() + j, boxes.end());
            
            // Calculate points for this removal and recurse
            int current_points = k * k + removeBoxesHelper(new_boxes);
            max_points = max(max_points, current_points);
            
            i = j; // Move to next different color
        }
        
        return max_points;
    }

    int removeBoxes(vector<int>& boxes) {
        return removeBoxesHelper(boxes);
    }
};
*/