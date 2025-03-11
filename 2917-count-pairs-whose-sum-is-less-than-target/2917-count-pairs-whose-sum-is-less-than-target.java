class Solution {
    public int countPairs(List<Integer> nums, int target) {
        Collections.sort(nums);
        int count = 0;
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            if (nums.get(low) + nums.get(high) < target) {
                count += (high - low);
                low++;
            } else {
                high--;
            }
        }

        return count;
    }
}