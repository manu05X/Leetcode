class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);         
        cin.tie(NULL);

        // Create a min-heap of size k
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // Iterate through the elements of the array
        for (int num : nums) {
            // Add element to the min-heap if its size is less than k
            if (minHeap.size() < k) {
                minHeap.push(num);
            } else {
                // Replace root with current element if it's greater than the root
                if (num > minHeap.top()) {
                    minHeap.pop(); // Remove root
                    minHeap.push(num); // Add current element
                }
            }
        }
        
        // The root of the min-heap will be the kth largest element
        return minHeap.top();
    }
};