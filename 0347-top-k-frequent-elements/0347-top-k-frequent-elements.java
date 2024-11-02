class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        int n = nums.length;

        HashMap<Integer, Integer> mp = new HashMap<>();

         // Count the frequency of each element
        for(int i =0; i < n; i++){
            mp.put(nums[i], mp.getOrDefault(nums[i],0)+1);
        }

        List<Map.Entry<Integer, Integer>> entryList = new ArrayList<>(mp.entrySet());
        
        // Sort the list based on the frequency in descending order
        entryList.sort((a, b) -> b.getValue() - a.getValue());
        
        int[] ans = new int[k];
        // Retrieve the top k elements
        for (int i = 0; i < k; i++) {
            ans[i] = entryList.get(i).getKey();
        }
        
        return ans;
    }
}