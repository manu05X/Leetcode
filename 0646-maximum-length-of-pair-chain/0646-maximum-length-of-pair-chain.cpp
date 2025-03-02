/*

pairs:{{-9, 8}, {-6, -2}, {-6, 9}, {-5, 3}, {-1, 4}, {0, 3}, {1, 6}, {8, 10}}
count:1
prev:8

*/

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        // Sort the pairs by the second element of each vector
        sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
            //return b[1]-a[1];
        });

        int count = 0;
        int prev = INT_MIN; // Initialize with a very small value

        for (const auto& p : pairs) {
            if (prev < p[0]) {
                count++;
                prev = p[1];
            }
        }

        return count;
    }
};