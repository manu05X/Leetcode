class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int n = letters.length;

        int lo = 0;
        int hi = n-1;

        while(lo <= hi){
            int mid = lo+(hi-lo)/2;

            if(letters[mid] > target){
                //if mid is idex 0, so return it
                if(mid == 0 || letters[mid-1] == target){
                    return letters[mid];
                }
                // if mid-1 elem is less than target then next greater elme/char is mid 
                else if(letters[mid-1] < target){
                    return letters[mid];
                }
                //if above case are not met then normal way i.e mid-1 to search in LHS
                // if mid elem is greter than target then elem is in LHS of mid so move hi to mid-1 to search in LHS
                hi = mid - 1;
            } else {

                lo = mid+1;
            }
        }

        return letters[0];
    }
}