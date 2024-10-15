/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int lo = 0, hi = n - 1;
        
        // Binary search to find the peak element
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        int peakIndex = lo;
        
        // If the target is the peak element, return its index
        if (mountainArr.get(peakIndex) == target) {
            return peakIndex;
        }
        
        // Binary search on the left half i.e increasing half
        lo = 0, hi = peakIndex;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int midVal = mountainArr.get(mid);
            if (midVal == target) {
                return mid;
            } else if (midVal < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        // Binary search on the right half decreasing half
        lo = peakIndex, hi = n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int midVal = mountainArr.get(mid);
            if (midVal == target) {
                return mid;
            } else if (midVal < target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        
        return -1;
    }
};