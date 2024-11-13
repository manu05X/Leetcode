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