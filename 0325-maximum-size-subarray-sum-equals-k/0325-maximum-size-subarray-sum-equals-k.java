class Solution {
    public int maxSubArrayLen(int[] nums, int k) {
        int n = nums.length;

        int maxLength = 0;
        int prefixSum = 0;

        HashMap<Integer, Integer> mp = new HashMap<>();

        for(int i = 0; i < n; i++){
            prefixSum += nums[i];

            // Check if all of the numbers seen so far sum to k.
            if(prefixSum == k){
                maxLength = i+1;
            }

            // If any subarray seen so far sums to k, then update the length of the longest_subarray. 
            if(mp.containsKey(prefixSum-k) == true){
                maxLength = Math.max(maxLength, i-mp.get(prefixSum-k));
            }

            // Only add the current prefix_sum index pair to the map if the prefix_sum is not already in the map.
            if(!mp.containsKey(prefixSum)){
                mp.put(prefixSum, i);
            }
        }

        return maxLength;
    }
}