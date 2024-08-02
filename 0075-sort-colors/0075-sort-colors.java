class Solution {
    public void sortColors(int[] nums) {
       // Initialize pointers:
        // 'left' is the position where the next 0 should go,
        // 'right' is the position one more than where the next 2 should go,
        // 'current' is the current index being considered.
        int left = 0, right = nums.length-1, current = 0;
      
        while (current <= right) { // Process elements until 'current' reaches 'right'
            if (nums[current] == 0) {
                // When a 0 is found, swap it with the element at 'left' position,
                // then move both 'left' and 'current' one step right.
                
                swap(nums, left, current);
                current++;
                ++left;
            } else if (nums[current] == 2) {
                // When a 2 is found, swap it with the element just before 'right' position,
                // then decrement 'right' to move it leftward.
                // Note 'current' is not incremented because the swapped element needs to be checked.
                
                swap(nums, right, current);
                --right;
            } else {
                // If the element is 1, just move 'current' one step to the right.
                ++current;
            }
        }
    }

    // Helper method to swap two elements in an array
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}