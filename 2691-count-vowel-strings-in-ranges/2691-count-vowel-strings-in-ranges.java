class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        int w = words.length;
        int q = queries.length;

        int[] ans = new int[q];
        HashSet<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u'));
        int[] prefixSum = new int[w];
        int sum = 0;
        
        for(int i = 0; i < w; i++){
            String currWord = words[i];
            if(vowels.contains(currWord.charAt(0)) && vowels.contains(currWord.charAt(currWord.length()-1))){
                sum++;
            }

            prefixSum[i] = sum;
        }


        for(int i = 0; i < q; i++){
            int[] currQuery = queries[i];
            ans[i] = prefixSum[currQuery[1]] - (currQuery[0] == 0 ? 0 : prefixSum[currQuery[0]-1]);
        }

        return ans;

    }
}