class Solution {
    public int subarraySum(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> mp = new HashMap<>();
        int sum = 0;
        int count = 0;
        mp.put(sum,1);

        for(int i = 0; i < n; i++){
            sum += nums[i];

            int diff = sum - k;

            if(mp.containsKey(diff)){
                count += mp.get(diff);
            }

            mp.put(sum, mp.getOrDefault(sum, 0)+1);
        }

        return count;
    }
}