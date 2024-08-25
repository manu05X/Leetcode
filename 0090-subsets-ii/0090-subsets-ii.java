class Solution {
    List<List<Integer>> ans = new ArrayList<>(); // This will store all unique subsets.

    // Helper function to perform depth-first search (DFS) to generate subsets.
    public void dfs(int[] nums, List<Integer> temp, int left){
        // Add the current subset to the list of all subsets.
        ans.add(new ArrayList<>(temp));

        // Iterate through the array starting from 'left' index.
        for(int i = left; i < nums.length; i++){
            // This condition ensures that we skip duplicate elements to avoid duplicate subsets.
            // Explanation:
            // 1. `i == left`: This allows the first element in the range to be added to the subset.
            // 2. `nums[i] != nums[i-1]`: If the current element is the same as the previous one (and not the first element in the range), we skip it to avoid duplicates.
            if(i == left || nums[i] != nums[i-1]){
                temp.add(nums[i]); // Add the current element to the temporary subset.
                dfs(nums, temp, i+1); // Recursively generate subsets including the current element.
                temp.remove(temp.size()-1); // Backtrack by removing the last added element to explore other possibilities.
            }
        }
    }

    // Main function to generate all unique subsets of the array.
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        List<Integer> temp = new ArrayList<>(); // Temporary list to store each subset.
        Arrays.sort(nums); // Sort the array to handle duplicates easily.
        dfs(nums, temp, 0); // Start DFS from the first index.

        return ans; // Return all unique subsets.
    }
}
