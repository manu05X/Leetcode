class Solution {
    public int longestPalindrome(String s) {
        int oddCount = 0;
        int evenCount = 0;
        boolean hasOdd = false;

        HashMap<Character, Integer> mp = new HashMap<>();
        for(Character x : s.toCharArray()){
            mp.put(x, mp.getOrDefault(x,0)+1);
        }


        for(Map.Entry<Character, Integer> entry : mp.entrySet()){
            //Character x = entry.getKey();
            Integer y = entry.getValue();
            
            if(y % 2 == 0){
                evenCount += y;
            } else {
                hasOdd = true;
                oddCount += y-1;
            }
        }

        int total = evenCount + oddCount + (hasOdd == true? 1:0);

        return total;
        
    }
}