class Solution {
public:
     vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(); // Number of rows in the matrix
        int cols = matrix[0].size(); // Number of columns in the matrix
        vector<vector<int>> dist(rows, vector<int>(cols, -1)); // Initialize the distance matrix with -1
        queue<pair<int, int>> queue; // Queue to store the matrix cells
      
        // Initialize the queue with all the cells that have 0s and set their distance to 0
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (matrix[row][col] == 0) {
                    dist[row][col] = 0;
                    queue.emplace(row, col);
                }
            }
        }
      
        // Defining directions for easy access to adjacent cells in matrix (up, right, down, left)
        vector<int> directions = {-1, 0, 1, 0, -1};

        // Perform Breadth-First Search
        while (!queue.empty()) {
            pair<int, int> cur = queue.front(); // Get current cell from the queue
            queue.pop();

            // Check all adjacent cells
            for (int i = 0; i < 4; ++i) { // Loop through all four possible directions
                int nextRow = cur.first + directions[i];   // Compute row index for adjacent cell
                int nextCol = cur.second + directions[i+1]; // Compute column index for adjacent cell

                // Check if the adjacent cell is within bounds and hasn't been visited
                if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols && dist[nextRow][nextCol] == -1) {
                    // If the cell is valid and unvisited, calculate its distance and add to queue
                    dist[nextRow][nextCol] = dist[cur.first][cur.second] + 1;
                    queue.emplace(nextRow, nextCol);
                }
            }
        }
      
        return dist; // Return the distance matrix after processing.
    }
};