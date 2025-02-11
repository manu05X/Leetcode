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