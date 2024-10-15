class Solution {
    public boolean increase(int [] arr){
        int n =arr.length;  
        /*
        12345
        1<2, 2<3, 3<4, 4<5
        */
        for(int i=0; i<n-1;i++)
        {
            if(arr[i]<=arr[i+1])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }

    public boolean decrease(int [] nums){
        int n=nums.length;
        for(int i=0; i<n-1;i++){
            if(nums[i]>=nums[i+1]){
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    } 

    public boolean isMonotonic(int[] nums) {
        int n= nums.length;
        boolean incFunction=increase(nums);
        boolean decFunction=decrease(nums);

        if(incFunction || decFunction ){
            return true;
        }
        else {
            return false;
        }
    }
}