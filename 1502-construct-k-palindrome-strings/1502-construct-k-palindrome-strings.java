class Solution {
    public boolean canConstruct(String s, int k) {
        int n = s.length();

        if(n < k){
            return false;
        }

        if(n == k) return true;

        int[] totalFreq = new int[26];
        int oddCount = 0;

        for(char c : s.toCharArray()){
            totalFreq[c - 'a']++;
        }


        for(int count : totalFreq){
            if(count % 2 == 1){
                oddCount++;
            }
        }


        return oddCount <= k;
    }
}