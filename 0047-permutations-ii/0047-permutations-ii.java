class Solution {
    // List to store all unique permutations
    private List<List<Integer>> permutations = new ArrayList<>();
    // Temporary list to store one permutation
    private List<Integer> tempPermutation = new ArrayList<>();
    // Array of numbers to create permutations from
    private int[] numbers;
    // Visited flags to track whether a number has been used in the current permutation
    private boolean[] visited;

    public List<List<Integer>> permuteUnique(int[] nums) {
        // Sort the numbers to ensure duplicates are adjacent
        Arrays.sort(nums);
        // Initialize class variables
        this.numbers = nums;
        visited = new boolean[nums.length];
        // Start the depth-first search from the first index
        dfs(0);
        // Return the list of all unique permutations found
        return permutations;
    }

    private void dfs(int index) {
        // Base case: If the current permutation is complete, add it to the list of permutations
        if (index == numbers.length) {
            permutations.add(new ArrayList<>(tempPermutation));
            return;
        }
        // Iterate over the numbers to build all possible permutations
        for (int i = 0; i < numbers.length; ++i) {
            // Skip the current number if it's already been used or if it's a duplicate and the duplicate hasn't been used
            if (visited[i] || (i > 0 && numbers[i] == numbers[i - 1] && !visited[i - 1])) {
                continue;
            }
            // Add the current number to the current permutation and mark it as visited
            tempPermutation.add(numbers[i]);
            visited[i] = true;
            // Recursively continue building the permutation
            dfs(index + 1);
            // Backtrack by removing the current number and unmarking it as visited
            visited[i] = false;
            tempPermutation.remove(tempPermutation.size() - 1);
        }
    }
}
