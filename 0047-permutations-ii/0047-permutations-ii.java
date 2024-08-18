class Solution {
    List<List<Integer>> ans = new ArrayList<>();

    public void dfs(int[] nums, int idx) {
        if (idx == nums.length) {
            List<Integer> tmp = new ArrayList<>();
            for (int x : nums) {
                tmp.add(x);
            }
            ans.add(tmp);
            return;
        }

        Set<Integer> used = new HashSet<>();
        for (int i = idx; i < nums.length; i++) {
            if (used.add(nums[i])) { // Check if nums[i] is already used in this position
                swap(nums, i, idx);
                dfs(nums, idx + 1);
                swap(nums, i, idx); // Backtrack to restore the original state
            }
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public List<List<Integer>> permuteUnique(int[] nums) {
        Arrays.sort(nums); // Sort initially to handle duplicates
        dfs(nums, 0);
        return ans;
    }
}
