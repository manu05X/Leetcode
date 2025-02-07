class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
        int n = nums.length;

        int maxLength = 0;
        int prefixSum = 0;

        HashMap<Integer, Integer> mp = new HashMap<>();

        for(int i = 0; i < n; i++){
            prefixSum += nums[i];

            if(prefixSum == k){
                maxLength = i+1;
            }

            if(mp.containsKey(prefixSum-k) == true){
                maxLength = Math.max(maxLength, i-mp.get(prefixSum-k));
            }

            if(!mp.containsKey(prefixSum)){
                mp.put(prefixSum, i);
            }
        }

        return maxLength;
    }
}