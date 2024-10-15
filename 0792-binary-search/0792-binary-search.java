class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;

        int lo = 0; 
        int hi = n-1;

        while(lo <= hi){
            int mid = lo + (hi-lo)/2;

            if(nums[mid] == target){
                return mid;
            }
            // if mid elem is less than target then target is in RHS of mid, so move lo to mid+1 to search in RHS
            else if(nums[mid] < target){
                lo = mid+1;
            }
            // if mid elem is greter than target then elem is in LHS of mid so move hi to mid-1 to search in LHS
            else {
                hi = mid-1;
            }
        }
        return -1;
    }
}
/*
target = 2

 0,1,2,3,4,5
-1,0,3,5,9,12

lo < hi 0 < 6
lo = 0, hi = 6, mid = 3, 5 > 2 => mid elem is greter than target so => hi = mid-1 to search in LHS hi = mid-1 = 2

0 < 2
lo = 0, hi = 2, mid = 1, 0 < 2 => mid elem is less than target so => hi = mid+1 to search in RHS lo = mid+1 = 1+1 = 2

2 == 2, hi == lo
lo = 2, hi = 2, mid = 2, 3 > 2 => mid elem is greter than target so => hi = mid-1 to search in LHS hi = mid-1 = 1

lo <= hi i.e 2<= 1 therefor break while loop

return -1

*/