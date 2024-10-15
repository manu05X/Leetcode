/**
 * // This is ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface ArrayReader {
 *     public int get(int index) {}
 * }
 */

class Solution {
    public int search(ArrayReader reader, int target) {
        int lo = 0;
        int hi = lo+1;

        while(lo <= hi){
            // Step 1: Find the appropriate `hi` where target could be
            if(target > reader.get(hi)){
                lo = hi;
                hi = hi*2; // Keep doubling `hi` until we find the right range
            }
            // Step 2: Perform binary search within the range [lo, hi]
            else if(target <= reader.get(hi))
            {
                int mid = lo + (hi-lo)/2;

                if(target == reader.get(mid)){
                    return mid;
                } 
                else if(target < reader.get(mid))
                {
                    hi = mid-1;
                } 
                else 
                {
                    lo = mid+1;
                }
            }
        }
        return -1;
    }
}