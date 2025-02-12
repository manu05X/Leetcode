class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int left = 1, right = 1e9; // Possible range of days

        // If we need more flowers than available, return -1
        if ((1LL* m * k) > n) 
            return -1;

        // Perform Binary Search on 'days'
        while (left < right) {
            int mid = (left + right) / 2; // Midpoint of the search range
            int flowers = 0, bouquets = 0;

            // Count possible bouquets for 'mid' days
            for (int j = 0; j < n; ++j) {
                if (bloomDay[j] > mid) {
                    flowers = 0; // Reset if flower has not bloomed
                } else {
                    ++flowers; // Count consecutive bloomed flowers
                    if (flowers >= k) {
                        bouquets++; // Make a bouquet
                        flowers = 0; // Reset flower count for next bouquet
                    }
                }
            }

            // If we can't make 'm' bouquets, increase days
            if (bouquets < m) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left; // Minimum days required
    }
};


// class Solution {
// public:
//         int minDays(vector<int>& A, int m, int k) {
//         int n = A.size(), left = 1, right = 1e9;
//         if ((m * k) > n) 
//             return -1;
//         while (left < right) {
//             int mid = (left + right) / 2, flow = 0, bouq = 0;
//             for (int j = 0; j < n; ++j) {
//                 if (A[j] > mid) {
//                     flow = 0;
//                 } else if (++flow >= k) {
//                     bouq++;
//                     flow = 0;
//                 }
//             }
//             if (bouq < m) {
//                 left = mid + 1;
//             } else {
//                 right = mid;
//             }
//         }
//         return left;
//     }
// };