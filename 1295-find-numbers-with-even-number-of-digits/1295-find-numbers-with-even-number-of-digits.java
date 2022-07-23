class Solution {
    public int findNumbers(int[] nums) {
        int n,ans = 0;
        for(int i = 0; i < nums.length; i++)
        {
            n=nums[i];
            if(( 10<=n && n<=99) || (1000<=n && n<=9999 ) || ( n==100000 ))
            {
               ans++;
            }
            
        }
        
        return ans;
    }
}