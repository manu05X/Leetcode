class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        ios_base::sync_with_stdio(false);         
        cin.tie(NULL);
        // Initialize the binary search bounds
        int left = 0;
        int right = arr.size() - k;

        // Perform binary search to find the start index of the k closest elements
        while (left < right) {
            // Calculate mid index (avoid potential overflow by using left + (right-left)/2)
            int mid = left + (right - left) / 2;
          
            // Compare the differences between x and elements at mid index and mid+k index
            // The goal is to find the smallest window such that the elements are closest to x
            if (x - arr[mid] <= arr[mid + k] - x) {
                // If the element at mid index is closer to x, or equally close
                // as the element at mid+k index (prefer the smaller element),
                // move the right bound to mid
                right = mid;
            } else {
                // Otherwise, if the element at mid+k index is closer to x,
                // move the left bound to mid + 1
                left = mid + 1;
            }
        }

        // Create and return a vector of k closest elements starting from the 'left' index
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};