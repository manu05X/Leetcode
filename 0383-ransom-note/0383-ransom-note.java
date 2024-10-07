class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int n = magazine.length();
        int m = ransomNote.length();

        Map<Character, Integer> mp = new HashMap<>();

        for(char ch : magazine.toCharArray()){
            mp.put(ch, mp.getOrDefault(ch,0)+1);
        }

        for(char ch : ransomNote.toCharArray()){
            if(!mp.containsKey(ch) || mp.get(ch) == 0){
                return false;
            }
            mp.put(ch, mp.get(ch)-1);
            
        }

        return true;
    }
}


/*
class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        int n = magazine.length();
        int m = ransomNote.length();

        Map<Character, Integer> mp = new HashMap<>();

        for(char ch : magazine.toCharArray()){
            mp.put(ch, mp.getOrDefault(ch,0)+1);
        }

        for(char ch : ransomNote.toCharArray()){
            if(mp.containsKey(ch)){
                mp.put(ch, mp.get(ch)-1);
            }
            return false;
        }

        return true;
    }
}
*/