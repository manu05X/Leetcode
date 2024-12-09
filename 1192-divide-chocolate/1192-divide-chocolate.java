class Solution {
    public int maximizeSweetness(int[] sweetness, int k) {
        // Initialize the binary search range
        int left = 1; // Minimum possible sweetness
        int right = 0; // Maximum possible sweetness (sum of all elements)

        for (int s : sweetness) {
            right += s;
        }

        // Perform binary search
        while (left <= right) {
            int mid = (left + right) / 2; // Midpoint of the range
            if (canSplit(sweetness, k, mid)) {
                // If we can split with at least k+1 pieces and each piece >= mid
                left = mid + 1; // Try to increase the minimum sweetness
            } else {
                right = mid - 1; // Otherwise, decrease the minimum sweetness
            }
        }

        return right; // The maximum minimum sweetness
    }

    private boolean canSplit(int[] sweetness, int k, int minSweetness) {
        int currentSum = 0; // Current piece's total sweetness
        int pieces = 0; // Number of pieces formed

        for (int s : sweetness) {
            currentSum += s;
            if (currentSum >= minSweetness) {
                pieces++; // Form a piece
                currentSum = 0; // Reset the sum for the next piece
            }
        }

        // We need at least k+1 pieces to satisfy the conditions
        return pieces >= k + 1;
    }
}
