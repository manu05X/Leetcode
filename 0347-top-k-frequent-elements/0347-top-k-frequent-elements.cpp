class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         // Create a frequency map to store the count of each element
        unordered_map<int,int> mp;
        for(int x : nums){
            mp[x]++;
        }
        vector<pair<int,int>> sortArray;
        // Create a vector of pairs v, where each pair consists of the frequency and the corresponding element.
        for(auto it : mp){
            sortArray.push_back(make_pair(it.second, it.first));
        }
        //Sort the vector v in descending order based on the frequency.
        sort(sortArray.rbegin(), sortArray.rend());

        vector<int>ans;
        // Iterate through the sorted vector v and insert the elements into the result vector ans until k elements are inserted.
        for(int i = 0; i < k; i++){
            ans.push_back(sortArray[i].second);
            
        }
        return ans;
    }
};

/*
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
*/

/*

This line is checking if the number of elements currently in the priority queue (i.e., pq.size()) exceeds the total number of elements that should not be part of the final result (mp.size() - k).

In other words, since we want the top k frequent elements, we are ensuring that once the priority queue contains the k most frequent elements, we start processing them for our result.

// if(pq.size() > (int)mp.size() - k)

*/