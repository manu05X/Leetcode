class Solution {
public:
    bool wordPattern(string pattern, string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int ns = s.size();
        int np = pattern.size();
        unordered_map<char, string> map_char;
        unordered_map<string, char> map_word;

        vector<string> word;
        string tmp = "";
        for(int i = 0; i < ns; i++){
            //cout << s[i] <<" "<<endl;
            if(s[i] == ' '){
                word.push_back(tmp);
                tmp = "";
            }
            else{
                //cout << s[i] <<" "<<endl;
                tmp += s[i];
            }
        }
        word.push_back(tmp);

        if (word.size() != pattern.size())
            return false;

        for(int i = 0; i < word.size(); i++)
        {
            char c = pattern[i];
            string w = word[i];

            if(map_char.find(c) == map_char.end()){
                if(map_word.find(w) != map_word.end()){
                    return false;
                }
                else
                {
                    map_word[w] = c;
                    map_char[c] = w;
                }
            }
            else
            {
                string mapped_word = map_char[c];
                if(mapped_word != w){
                    return false;
                }
            }
        }

        return true;
    }
};

/*
Some what similar

https://leetcode.com/problems/isomorphic-strings/description/?envType=study-plan-v2&envId=top-interview-150



*/