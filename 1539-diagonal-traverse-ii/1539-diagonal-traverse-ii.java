import java.util.*;

class Solution {
    public int[] findDiagonalOrder(List<List<Integer>> nums) {
        // Map to store diagonals with key as sum of indices (i + j)
        Map<Integer, List<Integer>> mp = new HashMap<>();
        int maxKey = 0;
        int totalElements = 0; // To calculate the size of the final array

        // Traverse through the matrix
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.get(i).size(); j++) {
                int key = i + j;
                maxKey = Math.max(key, maxKey); // Update maxKey

                //mp.putIfAbsent(key, new ArrayList<>());

                // Alternative to putIfAbsent
                if (!mp.containsKey(key)) {
                    mp.put(key, new ArrayList<>());
                }
                mp.get(key).add(nums.get(i).get(j)); // Add element to the corresponding diagonal
                totalElements++; // Track the total number of elements
            }
        }

        // Prepare the result array
        int[] ans = new int[totalElements];
        int index = 0;

        // Traverse through each diagonal and add the elements to the result array
        for (int i = 0; i <= maxKey; i++) {
            if (mp.containsKey(i)) {
                // Add the diagonal elements in reverse order
                List<Integer> diag = mp.get(i);
                Collections.reverse(diag); // Reverse to match the bottom-left traversal order
                for (int num : diag) {
                    ans[index++] = num;
                }
            }
        }

        return ans;
    }
}
