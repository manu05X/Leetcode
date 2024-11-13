class Solution {
    public int[] answerQueries(int[] nums, int[] queries) {
        int n = nums.length;
        
        // Sort the nums array
        Arrays.sort(nums);
        
        // Create a prefix sum array
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }
        
        // Create the answer array
        int[] ans = new int[queries.length];
        
        // For each query, find the upper bound in the prefix sum array
        for (int i = 0; i < queries.length; i++) {
            int x = queries[i];
            
            // Find the index using binary search
            int index = upperBound(nums, x);
            
            ans[i] = index;
        }
        
        return ans;
    }
    
    // Helper function to find the upper bound (similar to C++'s upper_bound)
    private int upperBound(int[] nums, int target) {
        int low = 0, high = nums.length;
        
        // Binary search to find the first element greater than target
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low;  // Return the index of the first element greater than target
    }
}


/*
    public int[] answerQueries(int[] A, int[] queries) {
        Arrays.sort(A);
        int n = A.length, m = queries.length, res[] = new int[m];
        for (int i = 1; i < n; ++i)
            A[i] += A[i - 1];
        for (int i = 0; i < m; ++i) {
            int j = Arrays.binarySearch(A, queries[i]);
            res[i] = Math.abs(j + 1);
        }
        return res;
    }
*/