class Solution {
public:
    int countLessEqual(vector<vector<int>>& matrix, int mid, int n) {
        int elementCount = 0;
        int row = n - 1;  // Start from the bottom-left corner
        int col = 0;

        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                elementCount += row + 1;  // Count all elements in the current column up to 'row'
                col++;
            } else {
                row--;  // Move up
            }
        }
        return elementCount;
    }

    // Only ONE definition of kthSmallest should exist
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];

        // Binary search on the value range
        while (left < right) {
            int mid = left + (right - left) / 2;
            int elementCount = countLessEqual(matrix, mid, n);

            if (elementCount < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};



/*
class Solution { // 28 ms, faster than 83.06%
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int m = matrix.size(), n = matrix[0].size(); // For general, the matrix need not be a square
        priority_queue<int> maxHeap;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                maxHeap.push(matrix[r][c]);
                if (maxHeap.size() > k) 
                    maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};

*/