class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         // Create a frequency map to store the count of each element
        unordered_map<int,int> mp;
        for(int x : nums){
            mp[x]++;
        }
        vector<int> ans;
        // Create a priority queue (max heap) to store pairs of frequencies and corresponding elements
        priority_queue<pair<int,int>> pq;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            // Push pairs of (frequency, element) into the priority queue
            pq.push({it->second, it->first});

            // If the size of the priority queue exceeds k, pop the top element
            if(pq.size() > (int)mp.size() - k) {
                ans.push_back(pq.top().second); // Push the element with the highest frequency to the answer
                pq.pop(); // Pop the top element from the priority queue
            }
        }

        // The answer vector contains the k most frequent elements
        return ans;
    }
};