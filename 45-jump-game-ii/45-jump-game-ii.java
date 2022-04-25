class Solution {
    public int jump(int[] nums) {
       int count = 0, currLast = 0, farthest = 0;
        
        for(int i = 0; i < nums.length - 1; i++)
        {
            // current Far point taht con be reached
            farthest = Math.max(farthest, i+nums[i]);
            
            // once currLast is reach then jump;
            if(i == currLast)
            {
                count++;
                currLast = farthest;
            }
        }
        
        return count; 
    }
}