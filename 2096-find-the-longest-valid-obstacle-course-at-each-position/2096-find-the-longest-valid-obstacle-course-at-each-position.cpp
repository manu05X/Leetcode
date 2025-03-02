class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> lis; // Stores increasing subsequence
        vector<int> ans(n); // Stores result for each index

        for (int i = 0; i < n; i++) {
            int height = obstacles[i];

            // Find the rightmost position where height can be inserted (allowing duplicates)
            int pos = upper_bound(lis.begin(), lis.end(), height) - lis.begin();

            // If pos is beyond the last index, extend lis
            if (pos == lis.size()) {
                lis.push_back(height);
            } else {
                lis[pos] = height; // Replace with a smaller value
            }

            ans[i] = pos + 1; // 1-based index
        }

        return ans;
    }
};