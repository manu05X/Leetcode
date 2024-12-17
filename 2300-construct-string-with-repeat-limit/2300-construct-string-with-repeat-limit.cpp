class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        // Count the frequency of each character
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Max-heap to prioritize characters by lexicographical order
        priority_queue<pair<char, int>> pq;
        for (auto [ch, count] : freq) {
            pq.push({ch, count});
        }

        string ans = "";
        while (!pq.empty()) {
            // Get the most frequent character
            auto [ch1, count1] = pq.top();
            pq.pop();

            // Append the character up to the repeatLimit times
            int useCount = min(count1, repeatLimit);
            ans.append(useCount, ch1);

            // If there's still some of this character left
            if (count1 > useCount) {
                // Check if we can use another character in between
                if (!pq.empty()) {
                    auto [ch2, count2] = pq.top();
                    pq.pop();

                    // Append one instance of the second character
                    ans.push_back(ch2);

                    // Reduce its count and push it back if needed
                    if (count2 > 1) {
                        pq.push({ch2, count2 - 1});
                    }

                    // Push back the remaining frequency of the first character
                    pq.push({ch1, count1 - useCount});
                } else {
                    // If no fallback character is available, break
                    break;
                }
            }
        }

        return ans;
    }
};

/*
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i = 0; i < n; i++){
            mp[s[i]]++;
        }

        priority_queue<pair<char, int>, vector<pair<char, int>>> pq;

        for(auto [key, value] : mp){
            pq.push({key, value});
        }

        string ans = "";
        while(!pq.empty()){
            int k = repeatLimit;
            auto [key, value] = pq.top();
            pq.pop();

            while(value <= k){
                ans += key;
            }

            if(value-repeatLimit > 0){
                 pq.push({key, value-repeatLimit});
            }

           
        }

        return ans;
    }
};

*/