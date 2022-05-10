class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> ans = new ArrayList<>();
        sumUntil(ans, new ArrayList<Integer>(), k, n, 1);
        return ans;
    }
    
    public void sumUntil(List<List<Integer>> ans, List<Integer> comb, int k, int target, int start)
    {
        if(comb.size() == k && target == 0)
        {
            List<Integer> li = new ArrayList<Integer>(comb);
            ans.add(li);
            return;
        }
        
        if(comb.size() < k)
        {
            for(int i = start; i <= 9; i++)
            {
                if(target-i < 0)
                    break;
                comb.add(i);
                sumUntil(ans, comb, k, target-i, i+1);
                comb.remove(comb.size()-1);
            }
        }
    }
}