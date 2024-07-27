class Solution {
    public int totalFruit(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();
        int left = 0;
        int maxPick = 0;

        for(int right = 0; right < n; right++){
            mp.put(nums[right], mp.getOrDefault(nums[right], 0)+1);

            while(mp.size() > 2){
                mp.put(nums[left], mp.getOrDefault(nums[left], 0)-1);
                if(mp.get(nums[left]) == 0){
                    mp.remove(nums[left]);
                }
                left++;
            }
            int currPick = right-left+1;
            maxPick = Math.max(currPick, maxPick);
        }

        return maxPick;
    }
}