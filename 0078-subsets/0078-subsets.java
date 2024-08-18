class Solution {
    List<List<Integer>> ans = new ArrayList<>();

    public void dfs(int[] nums, List<Integer> temp, int start){
         ans.add(new ArrayList<>(temp)); // Push the current subset into the resultant array

        for(int i = start; i < nums.length; i++){
            temp.add(nums[i]); // Add the current element to consider the subsets corresponding to it
            dfs(nums, temp, i+1); // Generate subsets for this array
            temp.remove(temp.size()-1);
        }
    }
    
    
    public List<List<Integer>> subsets(int[] nums) {
        
        List<Integer> temp = new ArrayList<>();

        dfs(nums, temp, 0);

        return ans;
    }
}