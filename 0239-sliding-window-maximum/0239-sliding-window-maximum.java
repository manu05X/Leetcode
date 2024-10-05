
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

/*

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        List<Integer> result = new ArrayList<>();
        Deque<Integer> window = new LinkedList<>();

        // Return an empty array if nums is empty
        if (nums.length == 0) {
            return new int[0];
        }

        // If k is greater than the array size, set k to nums.length
        if (k > nums.length) {
            k = nums.length;
        }

        // Process the first window
        for (int i = 0; i < k; i++) {
            // Remove elements smaller than the current element from the back of the deque
            while (!window.isEmpty() && nums[i] >= nums[window.getLast()]) {
                window.removeLast();
            }
            // Add current index to the back of the deque
            window.addLast(i);
        }
        
        // Add the maximum for the first window
        result.add(nums[window.getFirst()]);

        // Process the remaining windows
        for (int i = k; i < nums.length; i++) {
            // Remove elements smaller than the current element from the back of the deque
            while (!window.isEmpty() && nums[i] >= nums[window.getLast()]) {
                window.removeLast();
            }

            // Remove the index that is out of this window
            if (!window.isEmpty() && window.getFirst() <= i - k) {
                window.removeFirst();
            }
            
            // Add current index to the back of the deque
            window.addLast(i);
            // Add the maximum for this window
            result.add(nums[window.getFirst()]);
        }

        // Convert List<Integer> to int[]
        return result.stream().mapToInt(i -> i).toArray();
    }
}
*/