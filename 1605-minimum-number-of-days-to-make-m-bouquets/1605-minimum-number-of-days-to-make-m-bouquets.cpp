 class Solution {
public:
    bool canMakeBouquets(vector<int>& bloomDay, int days, int m, int k) {
        int bouquets = 0, flowers = 0;
        for (int bloom : bloomDay) {
            if (bloom <= days) {
                flowers++;
                if (flowers == k) {
                    bouquets++;
                    flowers = 0;  // Reset flower count after forming a bouquet
                }
            } else {
                flowers = 0;  // Reset if non-bloomed flower breaks adjacency
            }
            if (bouquets >= m) return true;  // Early exit
        }
        return false;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if ((long long)m * k > n) return -1;  // Check if making bouquets is impossible

        int left = *min_element(bloomDay.begin(), bloomDay.end());  // Min bloom day
        int right = *max_element(bloomDay.begin(), bloomDay.end()); // Max bloom day

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (canMakeBouquets(bloomDay, mid, m, k)) {
                right = mid;  // Try a smaller number of days
            } else {
                left = mid + 1;  // Increase days if bouquets can't be made
            }
        }
        return left;
    }
};


/*
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
                // If the flower is not bloomed
                if (bloomDay[j] > mid) {
                    flowers = 0; // Reset if flower has not bloomed
                } else {
                    // If the flower is bloomed, add to the set. Else reset the count.
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

*/