class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        
        if(n == 0)
            return 0;
        
        int[] maxRob = new int[n+1];
        
        maxRob[0] = 0;
        maxRob[1] = nums[0];
        
        for(int i = 2; i < n+1; i++)
        {
            maxRob[i] = Math.max(maxRob[i-1], maxRob[i-2]+nums[i-1]);
            //System.out.println(maxRob[i]+", "+nums[i-1]);
        }
        //System.out.print(maxRob);
        
        return maxRob[n];
    }
}