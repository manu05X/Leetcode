class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public void dfs(int[] candidates, int target, List<Integer> currSubarr, int start){
        if(target < 0){
            return;// If remain becomes negative, terminate the current branch of the backtracking
        }
        else if(target == 0){
            ans.add(new ArrayList<>(currSubarr));// If remain is zero, add the current combination to the result
        }
        else{
            for(int i = start; i < candidates.length; i++){
                currSubarr.add(candidates[i]);// Choose the current candidate
                dfs(candidates, target-candidates[i], currSubarr, i);// Recursively backtrack with updated remain
                currSubarr.remove(currSubarr.size()-1);// Remove the last element to backtrack
            }
        }
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if(target == 0){
            return ans;
        }
        List<Integer> curr = new ArrayList<>();
        dfs(candidates, target, curr, 0);

        return ans;
    }
}