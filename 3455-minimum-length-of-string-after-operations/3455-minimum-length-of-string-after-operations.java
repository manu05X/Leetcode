class Solution {
    public int minimumLength(String s) {
        int n = s.length();
        int[] charFreq = new int[26];

        for(int i = 0; i < n; i++){
            charFreq[s.charAt(i)-'a']++;
        }


        int ans = 0;
        for(int frequency : charFreq){
            if(frequency == 0) continue;

            if(frequency % 2 == 0){
                ans += 2;
            } else {
                ans += 1;
            }
        }

        return ans;

    }
}

// abaacbcbb
/*

a = 3
b = 4
c = 2



 */