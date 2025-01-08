class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                string& str1 = words[i];
                string& str2 = words[j];

                // Skip if the first string is larger than the second
                if(str1.size() > str2.size()){
                    continue;
                }

                // Check if str1 is both the prefix and suffix of str2
                if(str2.find(str1) == 0 && str2.rfind(str1) == str2.size()-str1.size()){
                    ++count;
                }
            }
        }

        return count;
    }
};