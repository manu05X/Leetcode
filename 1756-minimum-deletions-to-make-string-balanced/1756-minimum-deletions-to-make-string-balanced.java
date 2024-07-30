class Solution {
    public int minimumDeletions(String s) {
        int n = s.length();
        int bCount = 0;
        int deletCount = 0;

        for(int i = 0; i < n; i++){
            if(s.charAt(i) == 'b'){
                bCount++;
            } else {
                // If we encounter an 'a', decide whether to delete this 'a' or 
                // any 'b' encountered so far to get a sorted string 'aa...bb...'
                // The min function chooses the smaller of deletion an 'a' or any previous 'b'
                deletCount = Math.min(deletCount+1, bCount);
            }
        }

        return deletCount;
    }
}