/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        // if(reader.get(0)==target) 
        //     return 0;
        // if(reader.get(1)==target) 
        //     return 1;

        int start = 0;
        int end = start+1;

        while(start <= end)
        {
            if(target > reader.get(end))
            {
                start = end;
                end = end * 2;
            }
            else if(target <= reader.get(end))
            {
                int mid = start + (end-start)/2;
                if(reader.get(mid) == target){
                    return mid;
                }
                else if(target < reader.get(mid)){
                    end = mid-1;
                }
                else{
                    start = mid+1;
                }
            }
        }
        return -1;
    }
};