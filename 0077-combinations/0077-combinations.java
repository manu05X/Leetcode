class Solution {
    List<List<Integer>> ans = new ArrayList<>();

    public void dfs(int n, int k, List<Integer> curr, int start){
        if(curr.size() == k){
            ans.add(new ArrayList<>(curr));
            return;
        }

        for(int i = start; i<=n; i++){
            curr.add(i);
            dfs(n,k,curr,i+1);
            curr.remove(curr.size()-1);
        }
    }

    public List<List<Integer>> combine(int n, int k) {
        List<Integer> curr = new ArrayList();
        dfs(n,k,curr,1);

        return ans;
    }
}