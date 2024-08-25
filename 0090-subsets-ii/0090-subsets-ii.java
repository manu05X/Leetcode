class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public void dfs(int[] nums, List<Integer> temp, int left){
        ans.add(new ArrayList<>(temp));

        for(int i = left; i < nums.length; i++){
            if(i == left || nums[i] != nums[i-1]){
                temp.add(nums[i]);
                dfs(nums, temp, i+1);
                temp.remove(temp.size()-1);
            }
        }
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        
        List<Integer> temp = new ArrayList<>();
        Arrays.sort(nums);
        dfs(nums, temp, 0);

        return ans;
    }
}