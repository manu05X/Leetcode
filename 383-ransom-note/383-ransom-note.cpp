class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int l = magazine.size();
        
        if(n > l)
            return false;
        
        int count[26] = {0};
        for(char ch : magazine)
        {
            count[ch-'a']++;
        }
        
        for(char ch : ransomNote)
        {
            if(count[ch-'a']-- <= 0)
                return false;
        }
        
        return true;
    }
};