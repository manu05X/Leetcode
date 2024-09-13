class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
     int len=0;
        unordered_set<string> st;
        for (int i=0; i<wordList.size(); i++)
            st.insert(wordList[i]);
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()){
            int sz= q.size();
            len++;
            for (int yy=0; yy<sz; yy++){
                string curr= q.front();
                q.pop();
                if (curr==endWord)
                    return len;
                for (int i=0; i<curr.size(); i++){
                    for (char ch='a'; ch<='z'; ch++){
                        if (curr[i]==ch)continue;
                        string temp= curr;
                        temp[i]= ch;
                        if (st.find(temp)!=st.end()){
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};