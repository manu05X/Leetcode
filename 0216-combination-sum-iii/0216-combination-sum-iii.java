class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    public void backtrack(List<Integer> currComb, int k, int target, int idx){

        if(target == 0 && k == currComb.size()){
            ans.add(new ArrayList<>(currComb));
            return;
        }

        //we will iterate from 1 .to. 9
        for(int i = idx; i <= 9; i++){
            if(target-i >= 0 && target-i < target){
                currComb.add(i);
                backtrack(currComb, k,target-i,i+1);
                currComb.remove(currComb.size()-1);
            }
        }
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<Integer> currComb = new ArrayList<>();
        backtrack(currComb, k,n,1);

        return ans;
    }
}