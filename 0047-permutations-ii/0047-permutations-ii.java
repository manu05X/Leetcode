class Solution {
    List<Integer> currTemp = new ArrayList<>();
    List<List<Integer>> ans = new ArrayList<>();
    int[] elem;
    boolean[] visited;

    public void dfs(int idx){
        // Base case: if the permutation size is equal to the number of elements, add it to the answer
        if(idx == elem.length){
            ans.add(new ArrayList<>(currTemp));
            return;
        }
        
        for(int i = 0; i < elem.length; ++i){
            // Skip the current number if it's already been used or if it's a duplicate and the duplicate hasn't been used
            if (visited[i] || (i > 0 && elem[i] == elem[i - 1] && !visited[i - 1])) {
                continue;
            }
            if(!visited[i]){
                visited[i] = true;
                currTemp.add(elem[i]);
                dfs(idx+1);
                currTemp.remove(currTemp.size()-1);
                 visited[i] = false;
            }
        }
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums);
        elem = nums;
        visited = new boolean[nums.length];

        dfs(0);

        return ans;
    }
}