class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;

        int temp = 1;
        int[] ans = new int[n];
        for(int i = 0; i < n; i++){
            ans[i] = temp;
            temp*=nums[i];
        }

        temp = 1;
        for(int i = n-1; i >= 0; i--){
            ans[i]*= temp;
            temp *= nums[i];
        }

        return ans;
    }
}
/*
[4,5,1,8,2]

->
[1,4,20,20,160]
             <-
[80,16,16,2,1]

 */