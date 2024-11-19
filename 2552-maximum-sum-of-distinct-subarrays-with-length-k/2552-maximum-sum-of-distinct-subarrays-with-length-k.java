class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        int n = nums.length;
        long maxSum = Integer.MIN_VALUE;
        long currWindowSum = 0;

        HashMap<Integer, Integer> mp = new HashMap<>();
        int left = 0;


        for(int right = 0; right < n; right++){
            int x = nums[right];
            currWindowSum += x;
            mp.put(x, mp.getOrDefault(x,0)+1);
            int currWindowLength = right-left+1;

            while(currWindowLength > k){
                currWindowSum -= nums[left];
                mp.put(nums[left], mp.getOrDefault(nums[left],0)-1);

                if(mp.get(nums[left]) == 0){
                    mp.remove(nums[left]);
                }
                left++;

                currWindowLength = right-left+1;
            }

            if(k == currWindowLength && mp.size() == k){
                maxSum = Math.max(maxSum, currWindowSum);
            }
        }

        return maxSum == Integer.MIN_VALUE ? 0 : maxSum;
    }
}

/*
class Solution {
    public long maximumSubarraySum(int[] nums, int k) {
        int n = nums.length;
        long maxSum = 0;
        long currWindowSum = 0;

        HashMap<Integer, Integer> mp = new HashMap<>();
        int left = 0;

        for(int right = 0; right < n; right++){
            currWindowSum += nums[right];
            mp.put(nums[right], mp.getOrDefault(nums[right],0)+1);
            
            int currWindowLength = right-left+1;
            while(currWindowLength > k)
            {
                currWindowSum -= nums[left];
                mp.put(nums[left], mp.getOrDefault(nums[left],0)-1);

                if(mp.get(nums[left]) == 0){
                    mp.remove(nums[left]);
                }
                currWindowLength--;
                left++;
            }
            // Update maxSum if the window size is k and all elements are distinct
            if (currWindowLength == k && mp.size() == k) {
                maxSum = Math.max(maxSum, currWindowSum);
            }
        }
        return maxSum;
    }
}

 */