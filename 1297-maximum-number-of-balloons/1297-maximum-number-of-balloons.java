class Solution {
    public int maxNumberOfBalloons(String text) {
        int n = text.length();
        
        Map<Character, Integer> mp = new HashMap<>();
        StringBuilder temp = new StringBuilder("balloon");

        for(int i = 0; i < temp.length(); i++){
            mp.put(temp.charAt(i),0);
        }

        for(char c : text.toCharArray()){
            mp.put(c, mp.getOrDefault(c,0)+1);
        }

        mp.put('l',mp.getOrDefault('l',0)/2);
        mp.put('o',mp.getOrDefault('o',0)/2);

        int ans = Integer.MAX_VALUE;

        ans = Math.min(ans, mp.get('b'));
        ans = Math.min(ans, mp.get('a'));
        ans = Math.min(ans, mp.get('l'));
        ans = Math.min(ans, mp.get('o'));
        ans = Math.min(ans, mp.get('n'));

        return ans;
    }
}