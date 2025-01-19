class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        // Edge case: If the matrix is too small, no water can be trapped
        if (heightMap.empty() || heightMap[0].empty()) return 0;

        int m = heightMap.size();    // Number of rows
        int n = heightMap[0].size(); // Number of columns
        int water = 0;               // Total water volume that can be trapped

        // Priority queue to always process the lowest boundary first
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;

        // Visited array to keep track of visited cells
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add all boundary cells to the priority queue and mark them as visited
        for (int i = 0; i < m; ++i) {
            minHeap.push({heightMap[i][0], {i, 0}});
            minHeap.push({heightMap[i][n - 1], {i, n - 1}});
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }
        for (int j = 1; j < n - 1; ++j) {
            minHeap.push({heightMap[0][j], {0, j}});
            minHeap.push({heightMap[m - 1][j], {m - 1, j}});
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

        // Directions for traversing adjacent cells
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // Process the cells in the priority queue
        while (!minHeap.empty()) {
            auto [currentHeight, cell] = minHeap.top();
            minHeap.pop();

            int x = cell.first, y = cell.second;

            // Check all four neighbors
            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                // Skip out-of-bounds or already visited cells
                if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[nx][ny]) continue;

                // Water can only be trapped if the height of the current cell is greater than the neighbor
                water += max(0, currentHeight - heightMap[nx][ny]);

                // Update the neighbor's height to be the maximum of its height and the current boundary height
                minHeap.push({max(currentHeight, heightMap[nx][ny]), {nx, ny}});

                // Mark the neighbor as visited
                visited[nx][ny] = true;
            }
        }

        return water; // Return the total volume of trapped water
    }
};