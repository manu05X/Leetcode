class NumArray {
    private int[] segTree; // Segment tree array
    private int n;         // Size of the input array

    // Helper method to build the segment tree
    private void buildSegTree(int[] nums, int node, int start, int end) {
        if (start == end) {
            // If start == end, it's a leaf node, store the value from the input array
            segTree[node] = nums[start];
        } else {
            // Recursively build the segment tree
            int mid = start + (end - start) / 2;
            buildSegTree(nums, 2 * node + 1, start, mid);     // Left child
            buildSegTree(nums, 2 * node + 2, mid + 1, end);   // Right child
            // Store the sum of the left and right children in the current node
            segTree[node] = segTree[2 * node + 1] + segTree[2 * node + 2];
        }
    }

    // Helper method to query the sum of a range
    private int rangeQuery(int node, int start, int end, int left, int right) {
        // Case 1: Query range is completely outside the current range
        if (left > end || right < start) {
            return 0;
        }
        // Case 2: Current range is completely inside the query range
        if (left <= start && right >= end) {
            return segTree[node];
        }
        // Case 3: Partial overlap, query both left and right subtrees
        int mid = start + (end - start) / 2;
        int leftSum = rangeQuery(2 * node + 1, start, mid, left, right);
        int rightSum = rangeQuery(2 * node + 2, mid + 1, end, left, right);
        return leftSum + rightSum;
    }

    // Constructor to initialize the segment tree using the input array
    public NumArray(int[] nums) {
        n = nums.length;
        segTree = new int[4 * n];  // Resize the segment tree array to 4 * n
        buildSegTree(nums, 0, 0, n - 1);  // Build the segment tree starting from node 0
    }

    // Public method to return the sum of elements in the range [left, right]
    public int sumRange(int left, int right) {
        return rangeQuery(0, 0, n - 1, left, right);  // Query the segment tree starting from node 0
    }
}


/*
class NumArray {
    public int[] sum;
    public NumArray(int[] nums) {
        int n = nums.length;
        sum = new int[n+1];

        for(int i = 0; i < n; i++){
            sum[i+1] = sum[i]+nums[i];
        }
    }
    
    public int sumRange(int left, int right) {
        
        return sum[right+1] - sum[left];
    }
}
*/


// class NumArray {
//     public int[] arr;
//     public NumArray(int[] nums) {
//         arr = nums;
//     }
    
//     public int sumRange(int left, int right) {
//         int sum = 0;
//         for(int i = left; i <= right; i++){
//             sum+= arr[i];
//         }
//         return sum;
//     }
// }

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(left,right);
 */