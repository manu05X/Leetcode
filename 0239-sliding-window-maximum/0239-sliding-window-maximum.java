class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        int[] ans = new int[n-k+1];// Array to store the max values for each window

        Deque<Integer> q = new ArrayDeque<>();// Double-ended queue to maintain the max element indices

        int l = 0;
        for(int r = 0; r < n; r++){
            // Remove the indices of elements from the deque that are out of the current window
            if(!q.isEmpty() && r-k+1 > q.peekFirst()){
                q.pollFirst();
            }
            // Remove indices of elements from the deque that are less than
            // the current element nums[i] since they are not useful
            while(!q.isEmpty() && nums[r] >= nums[q.peekLast()]){
                q.pollLast();
            }
            // Add current element's index to the deque
            q.offer(r);
            // When we've hit size k, add the current max to the result
            // This corresponds to the index at the front of the deque
            if(r >= k-1){
                ans[l++] = nums[q.peekFirst()];
            }
        }

        return ans;
    }
}