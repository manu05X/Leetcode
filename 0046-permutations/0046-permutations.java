class Solution {
    List<List<Integer>> ans = new ArrayList<>();

    public void dfs(int[] nums, int idx){
        //The ArrayList constructor that takes a Collection as an argument expects a collection of Integer objects, not a primitive int[] array.
        // if(idx == nums.length){
        //     List<Integer> temp = new ArrayList<>(nums);
        //     ans.add(temp);
        //     return;
        // }
        if(idx == nums.length){
            List<Integer> curr = new ArrayList<>();
            for(int x : nums){
                curr.add(x);
            }
            ans.add(curr);
            return;
        }

        for(int i = idx; i < nums.length; i++){
            swap(nums,i, idx);
            dfs(nums, idx+1);
            swap(nums,i, idx);
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public List<List<Integer>> permute(int[] nums) {
        dfs(nums, 0);

        return ans;
    }
}