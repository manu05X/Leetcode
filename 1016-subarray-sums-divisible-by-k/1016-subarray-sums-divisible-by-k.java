class Solution {
    public int subarraysDivByK(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer, Integer> mp = new HashMap<>();

        int cumulativeSum = 0;
        int countSubarraySum = 0;

        mp.put(0,1);

        for(int i = 0; i < n; i++){
            int x = cumulativeSum+nums[i];

            cumulativeSum = (x % k + k)% k;

            if(mp.containsKey(cumulativeSum) == true){
                countSubarraySum += mp.get(cumulativeSum);
            }

            mp.put(cumulativeSum, mp.getOrDefault(cumulativeSum,0)+1);
        }

        return countSubarraySum;
    }
}