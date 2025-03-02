class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;  // Base case: 0 can be represented with 0 perfect squares.

        // Fill dp table for each number from 1 to n
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};


// class Solution {
// public:
//     int numSquares(int n) {
//         static vector<int> counter = {0};
//         while (counter.size() <= n) {
//             int m = counter.size();
//             int curr = 1e9;
//             for (int i = 1; i * i <= m; ++i) {
//                 curr = min(curr, counter[m - i * i] + 1);
//             }
//             counter.push_back(curr);
//         }
//         return counter[n];
//     }
// };


// class Solution {
// public:
//     int numSquares(int n) {
//         queue<int> q;
//         unordered_set<int> visited;
//         q.push(n);
//         int steps = 0;

//         while (!q.empty()) {
//             int size = q.size();
//             steps++;

//             for (int i = 0; i < size; i++) {
//                 int curr = q.front();
//                 q.pop();

//                 // Try subtracting all perfect squares
//                 for (int j = 1; j * j <= curr; j++) {
//                     int next = curr - j * j;

//                     if (next == 0) return steps;  // Found the shortest path
//                     if (!visited.count(next)) {
//                         visited.insert(next);
//                         q.push(next);
//                     }
//                 }
//             }
//         }

//         return steps;
//     }
// };
