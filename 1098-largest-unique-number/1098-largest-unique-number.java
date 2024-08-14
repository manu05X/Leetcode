class Solution {
    public int largestUniqueNumber(int[] nums) {
        int n = nums.length;
        Map<Integer,Integer> mp = new HashMap<>();

        for(int i = 0; i < n; i++){
            mp.put(nums[i], mp.getOrDefault(nums[i],0)+1);
        }
        int ans = -1;
        for(Map.Entry<Integer, Integer> x : mp.entrySet()){
            if(x.getValue() == 1){
                ans = Math.max(x.getKey(), ans);
            }
        }

        return ans;
    }
};
