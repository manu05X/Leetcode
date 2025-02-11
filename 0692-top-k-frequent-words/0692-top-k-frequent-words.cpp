class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        // Step 1: Count the frequency of each word using a map
        map<string, int> cnt;
        for (string& word : words) {
            cnt[word]++;
        }

        // Step 2: Use a min-heap (priority queue) to maintain the top k frequent words
        priority_queue<pair<int, string>> h;
        for (auto& p : cnt) {
            h.push({-p.second, p.first});  // Store negative frequency for min-heap behavior
            
            if (h.size() > k) h.pop();  // Maintain only k elements
        }

        // Step 3: Extract elements from the heap and sort them lexicographically
        vector<pair<int, string>> candidates;
        while (!h.empty()) {
            candidates.push_back(h.top());
            h.pop();
        }
        
        // Step 4: Sort based on frequency and lexicographical order
        sort(candidates.begin(), candidates.end());

        // Step 5: Extract the top K words
        vector<string> res;
        for (auto& p : candidates) {
            res.push_back(p.second);
        }
        
        return res;
    }
};


/*
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();

        unordered_map<string, int> mp;

        for(int i = 0; i < n; i++){
            mp[words[i]]++;
        }

        // Step 2: Create a min-heap (priority queue) with a custom comparator.
        // The heap will store (frequency, word) pairs.
        // The comparator ensures sorting by frequency (higher first) and lexicographically (if frequency is the same).
        auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first || (a.first == b.first && a.second < b.second);
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);

        // Step 3: Push elements into the heap and maintain only k elements.
        for(auto& [word,  freq] : mp){
            pq.push({freq, word});

            if(pq.size() > k){
                pq.pop(); // Remove the least frequent element
            }
        }

        // Step 4: Extract k most frequent words from the heap (in reverse order).
        vector<string> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        // Step 5: Reverse the result to get the highest frequency words first.
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

*/