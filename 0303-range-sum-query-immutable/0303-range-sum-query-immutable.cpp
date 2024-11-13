class NumArray {
public:
    int n;                    // Size of the input array
    vector<int> segTree;       // Segment tree to store sum of subarrays

    // Function to build the segment tree
    // node - current index in the segment tree
    // start, end - range of indices in the original array that this node represents
    void buildSegTree(vector<int>& nums, int node, int start, int end) {
        // Base case: if the start and end index are the same, it's a leaf node
        // Store the corresponding element from the original array
        if(start == end){
            segTree[node] = nums[start];
        } 
        // Recursive case: otherwise, split the range into two halves
        else {
            int mid = start + (end - start) / 2;  // Find the middle point
            // Recursively build the left child (2*node+1) and right child (2*node+2)
            buildSegTree(nums, 2*node + 1, start, mid);
            buildSegTree(nums, 2*node + 2, mid + 1, end);
            // Store the sum of the left and right children in the current node
            segTree[node] = segTree[2*node + 1] + segTree[2*node + 2];
        }
    }

    // Function to query the sum of a range [left, right]
    // node - current index in the segment tree
    // start, end - range of indices in the original array that this node represents
    // left, right - the query range (inclusive)
    int rangeQuery(int node, int start, int end, int left, int right) {
        // Case 1: If the query range is completely outside the current range, return 0
        if(left > end || right < start) {
            return 0;
        }
        // Case 2: If the current range is completely inside the query range, return the value stored in this node
        if(left <= start && right >= end) {
            return segTree[node];
        }
        // Case 3: If there is a partial overlap, split the query into two parts
        int mid = start + (end - start) / 2;
        // Recursively query the left child and right child, and sum the results
        int leftSum = rangeQuery(2*node + 1, start, mid, left, right);
        int rightSum = rangeQuery(2*node + 2, mid + 1, end, left, right);
        return leftSum + rightSum;  // Return the sum of both halves
    }

    // Constructor to initialize the segment tree using the input array `nums`
    NumArray(vector<int>& nums) {
        n = nums.size();           // Store the size of the input array
        segTree.resize(4*n);       // Resize the segment tree to 4 * n to accommodate all nodes
        buildSegTree(nums, 0, 0, n - 1);  // Build the segment tree starting from node 0
    }

    // Function to return the sum of elements between indices `left` and `right` (inclusive)
    int sumRange(int left, int right) {
        return rangeQuery(0, 0, n - 1, left, right);  // Query the segment tree from node 0
    }
};




/*
class NumArray {
public:
    vector<int>arr;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        arr.push_back(0);

        for(int i = 0; i < n; i++){
            arr.push_back(arr[i]+nums[i]);
        }
    }
    
    int sumRange(int left, int right) {

        return arr[right+1] - arr[left];
    }
};

*/

// class NumArray {
// public:
//     vector<int> arr;
//     NumArray(vector<int>& nums) {
//         arr = nums;
//     }
    
//     int sumRange(int left, int right) {
//         int sum = 0;
//         for(int i = left; i <= right; i++){
//             sum += arr[i];
//         }

//         return sum;
//     }
// };

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */