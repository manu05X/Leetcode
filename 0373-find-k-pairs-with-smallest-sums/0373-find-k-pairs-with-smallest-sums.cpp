class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Get the sizes of the two input arrays
        int m = nums1.size();
        int n = nums2.size();

        // Initialize the result vector to store the k smallest pairs
        vector<vector<int>> ans;

        // Use a set to keep track of visited pairs to avoid duplicates
        set<pair<int, int>> visited;

        // Use a min-heap to efficiently get the smallest sum pairs
        // The heap stores pairs of (sum, (i, j)) where i and j are indices in nums1 and nums2
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> minHeap;

        // Start by pushing the pair (0, 0) into the heap, which is the smallest possible pair initially
        minHeap.push({nums1[0] + nums2[0], {0, 0}});
        visited.insert({0, 0});

        // Continue until we have found k pairs or the heap is empty
        while (k-- && !minHeap.empty()) {
            // Get the pair with the smallest sum from the heap
            auto top = minHeap.top();
            minHeap.pop();
            int i = top.second.first;  // Index in nums1
            int j = top.second.second; // Index in nums2

            // Add the current pair to the result
            ans.push_back({nums1[i], nums2[j]});

            // Explore the next possible pair by incrementing the index in nums1
            if (i + 1 < m && visited.find({i + 1, j}) == visited.end()) {
                minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
                visited.insert({i + 1, j});
            }

            // Explore the next possible pair by incrementing the index in nums2
            if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
                visited.insert({i, j + 1});
            }
        }

        // Return the k smallest pairs
        return ans;
    }
};