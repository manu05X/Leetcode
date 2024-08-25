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
                if(i > start && candidates[i] == candidates[i-1]) continue;
                if(candidates[i] <= target){
                    currSubarr.add(candidates[i]);// Choose the current candidate
                    dfs(candidates, target-candidates[i], currSubarr, i+1);// Recursively backtrack with updated remain
                    currSubarr.remove(currSubarr.size()-1);// Remove the last element to backtrack
                }
            }
        }
    }
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        if(target == 0){
            return ans;
        }
        List<Integer> curr = new ArrayList<>();
        Arrays.sort(candidates);
        dfs(candidates, target, curr, 0);

        return ans;
    }
}