class Solution {
    public int longestConsecutive(int[] nums) {
        int n = nums.length;
        Set<Integer> num_set = new HashSet<Integer>();
        for (int num : nums) {
            num_set.add(num);
        }

        int longestStreak = 0;
        for(int i = 0; i < n; i++)
        {
            if(!num_set.contains(nums[i]-1))
            {
                int currentStreak = 1;
                int currentNum = nums[i];

                while(num_set.contains(currentNum+1))
                {
                    currentNum = currentNum+1;
                    currentStreak += 1;
                }
                longestStreak = Math.max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
}