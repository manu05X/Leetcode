class Solution {
    void recurUtil(const string& word, string curr, int idx, vector<string>& ans, int count) {
        int n = word.size();
        if(idx == n) {
            if(count!=0)
                curr += to_string(count);
            ans.push_back(curr);
            return;
        }
        //  Take curr element into abbreviation
        recurUtil(word,curr,idx+1,ans,count+1);
        
        //  Taking curr into string as it is and then moving ahead
        if(count != 0) {
            curr += to_string(count);
            count = 0;
        }
        curr.push_back(word[idx]);
        recurUtil(word,curr,idx+1,ans,count);
    }
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> ans;
        string curr;
        recurUtil(word,curr,0,ans,0);
        return ans;
    }
};