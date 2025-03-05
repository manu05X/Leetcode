class Solution {
public:
     int findMax(vector<int>& piles) {
        int res = INT_MIN;
        for(int i =0;i< piles.size();i++) {
            res = max(res, piles[i]);
        }
        return res;
     }

    int calculateTotalHours(vector<int> & piles, int mid) {
        int totalh = 0;
        for (int bananas : piles) {
            totalh += bananas/mid + (bananas % mid != 0);  
        }
        return totalh;
     }

    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = findMax(piles);
        while(lo < hi) {
            int mid = (lo+hi)/2;
            int totalh = calculateTotalHours(piles,mid);

             if(totalh<=h) {
                hi = mid;
             } else {
                lo = mid+1;
             }
        }
        return lo;
    }
};