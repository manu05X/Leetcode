class Solution {
    public void dfs(int[] arr, List<List<Integer>> ans, List<Integer> comb, int target,int idx)
    {
        if(target == 0)
        {
            ans.add(new ArrayList<>(comb));
            return;
        }
        
        for(int i = idx; i < arr.length; i++)
        {
            if(target >= arr[i])
            {
                comb.add(arr[i]);
                dfs(arr, ans, comb ,target - arr[i], i);
                comb.remove(comb.size()-1);
            }
        }
    }
    public List<List<Integer>> combinationSum(int[] arr, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        dfs(arr, ans,new ArrayList<>() ,target,0);
        return ans;
        
    }
}