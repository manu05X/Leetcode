class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
		if (ransomNote.length() > magazine.length()) return false;
        int[] alphabets_counter = new int[26];
        
        for (char c : magazine.toCharArray())
            alphabets_counter[c-'a']++;

        for (char c : ransomNote.toCharArray()){
            if (alphabets_counter[c-'a'] == 0) return false;
            alphabets_counter[c-'a']--;
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
            if(!mp.containsKey(ch) || mp.get(ch) == 0){
                return false;
            }
            mp.put(ch, mp.get(ch)-1);
            
        }

        return true;
    }
}
*/


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