
class Solution {
public:
    static bool compare(pair<int, int>& pair1, pair<int, int>& pair2) {
        if (pair1.first != pair2.first) 
            return pair1.first > pair2.first; // Min-Heap by value
        return pair1.second > pair2.second; // If values are equal, prefer smaller index
    }

    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> marked(n, false); // Tracks marked elements

        long long ans = 0;

        // Priority queue with a custom comparator
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&compare)> pq(compare);

        // Fill priority queue with (value, index) pairs
        for (int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        // Process elements in priority queue
        while (!pq.empty()) {
            pair<int, int> element = pq.top();
            pq.pop();
            int number = element.first;
            int index = element.second;

            // Check if the element is already marked
            if (!marked[index]) {
                ans += number;
                marked[index] = true;

                // Mark adjacent elements if they exist
                if (index - 1 >= 0) {
                    marked[index - 1] = true;
                }
                if (index + 1 < n) {
                    marked[index + 1] = true;
                }
            }
        }

        return ans;
    }
};

