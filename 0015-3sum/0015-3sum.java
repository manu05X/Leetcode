class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();

        for(int i = 0; i < n-2; i++){
            if(i == 0 || nums[i-1] != nums[i]){
                int lo = i+1;
                int hi = n-1;

                while(lo < hi){
                    int sum = nums[lo] + nums[hi] + nums[i];

                    if(sum < 0){
                        lo++;
                    }
                    else if(sum > 0){
                        hi--;
                    }
                    else{

                        ans.add(Arrays.asList(nums[i], nums[lo++], nums[hi--]));
                        while (lo < hi && nums[lo] == nums[lo - 1]) // to skip the duplicate element
                            ++lo;
                    }
                }
            }
        }

        return ans;
    }
}