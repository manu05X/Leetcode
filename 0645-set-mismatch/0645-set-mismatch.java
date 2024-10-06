class Solution {
    public int[] findErrorNums(int[] nums) {
        int dup = -1, missing = 1;
        for (int i = 0; i < nums.length; i++) {
            int n = nums[i];
            // If the number at the absolute value of n minus 1 is negative, we found the duplicate
            if (nums[Math.abs(n) - 1] < 0)
                dup = Math.abs(n);
            else // Mark the visited number by negating its value
                nums[Math.abs(n) - 1] *= -1;
        }
        // Iterate through the modified array to find the missing number
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > 0)
                missing = i + 1;
        }
        return new int[]{dup, missing};
    }
}