class Solution {
    public int largestUniqueNumber(int[] nums) {
        int n = nums.length;
        Map<Integer,Integer> mp = new HashMap<>();

        for(int i = 0; i < n; i++){
            mp.put(nums[i], mp.getOrDefault(nums[i],0)+1);
        }
        int ans = -1;
        for(int i = 0; i < n; i++){
            if(mp.get(nums[i]) == 1){
                ans = Math.max(nums[i], ans);
            }
        }

        return ans;
    }
}