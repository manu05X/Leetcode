class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int n = ransomNote.size();
        int m = magazine.size();

        if(n > m){
            return false;
        }
        //initialize an array of alphabets counter of size 26
        vector<int> alphabet_counter(26,0);
        for(int i = 0; i < m; i++){
            //increment the counter for that character
            alphabet_counter[magazine[i]-'a']++;
        }

        for(int i = 0; i<n;i++){
            // if the charachter doesn't exists in magazine for ransomNote, we return false
            if(alphabet_counter[ransomNote[i]-'a'] == 0){
                return false;
            }
            //if it does exists, we decrement the counter of that charachter from its own index
            alphabet_counter[ransomNote[i]-'a']--;
        }
        return true;       
    }
};