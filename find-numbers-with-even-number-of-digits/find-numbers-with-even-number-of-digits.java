class Solution {
    public int findNumbers(int[] nums) {
        int ans = 0;
        for(int i = 0; i < nums.length; i++)
        {
            int c = 1;
            int cn = nums[i];
            while(cn>= 10)
            {
                c++;
                cn/=10;
            }
            
            if(c%2 == 0)
                ans++;
            
        }
        
        return ans;
    }
}