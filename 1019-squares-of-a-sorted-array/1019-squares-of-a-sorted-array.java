class Solution {
    public int[] sortedSquares(int[] nums) {
        int n = nums.length;
        int left = 0;
        int right = n-1;

        int ans[] = new int[n]; //

        // iterator for ans
        for(int i = n-1; i >= 0; i--)
        {
            int temp = 0;
            if(Math.abs(nums[left]) < Math.abs(nums[right])){
                temp = nums[right];
                right--;
            }
            else{
                temp = nums[left];
                left++;
            }
            ans[i] = temp*temp;
        }

        return ans;
    }
}

        // // Sort the array
        // Arrays.sort(nums);
        
        // // For descending order
        // Integer[] numsWrapper = Arrays.stream(nums).boxed().toArray(Integer[]::new);
        // Arrays.sort(numsWrapper, Collections.reverseOrder());