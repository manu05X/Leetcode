class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int q = queries.size();
        
        // Store queries that need processing by their maximum index
        // Format: storeQueries[index] = vector of {maxHeight, queryIndex}
        vector<vector<vector<int>>> storeQueries(n);
        
        // Min heap to process queries efficiently
        // Format: {height requirement, query index}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        // Initialize result array with -1 (indicating no answer found yet)
        vector<int> result(q, -1);
        
        // Process queries and handle simple cases immediately
        for (int queryIdx = 0; queryIdx < q; queryIdx++) {
            int a = queries[queryIdx][0];
            int b = queries[queryIdx][1];
            
            // Case 1: Same building
            if (a == b) {
                result[queryIdx] = a;
                continue;
            }
            
            // Case 2: First building is lower than second building (when a < b)
            if (a < b && heights[a] < heights[b]) {
                result[queryIdx] = b;
                continue;
            }
            
            // Case 3: Second building is lower than first building (when a > b)
            if (a > b && heights[a] > heights[b]) {
                result[queryIdx] = a;
                continue;
            }
            
            // Complex case: Need to find a building to the right that's higher than both
            int maxIndex = max(a, b);
            int maxHeight = max(heights[a], heights[b]);
            storeQueries[maxIndex].push_back({maxHeight, queryIdx});
        }
        
        // Process each building from left to right
        for (int currIdx = 0; currIdx < n; currIdx++) {
            // Process any pending queries that can be answered with current building
            while (!minHeap.empty() && minHeap.top()[0] < heights[currIdx]) {
                int queryIdx = minHeap.top()[1];
                result[queryIdx] = currIdx;
                minHeap.pop();
            }
            
            // Add new queries that start at current index
            for (const auto& query : storeQueries[currIdx]) {
                minHeap.push(query);
            }
        }
        
        return result;
    }
};




/*
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        vector<int> ans(queries.size());
        
        // Sort queries to process them in order of second index
        vector<pair<pair<int,int>, int>> sortedQueries;
        for(int i = 0; i < queries.size(); i++) {
            int a = min(queries[i][0], queries[i][1]);
            int b = max(queries[i][0], queries[i][1]);
            sortedQueries.push_back({{b, a}, i});
        }
        sort(sortedQueries.begin(), sortedQueries.end());
        
        // Stack to maintain potential answers
        stack<pair<int,int>> st;  // {height, index}
        int queryIndex = sortedQueries.size() - 1;
        
        // Process buildings from right to left
        for(int i = n-1; i >= 0; i--) {
            // Remove buildings that are shorter and won't be used
            while(!st.empty() && st.top().first <= heights[i]) {
                st.pop();
            }
            st.push({heights[i], i});
            
            // Process all queries that start at current position
            while(queryIndex >= 0 && sortedQueries[queryIndex].first.first == i) {
                int originalIndex = sortedQueries[queryIndex].second;
                int a = sortedQueries[queryIndex].first.second;
                int b = sortedQueries[queryIndex].first.first;
                
                // If same building or one building is taller than the other
                if(a == b) {
                    ans[originalIndex] = a;
                } else if(heights[a] < heights[b]) {
                    ans[originalIndex] = b;
                } else {
                    // Find the first building to the right that is taller than both
                    bool found = false;
                    stack<pair<int,int>> temp = st;
                    while(!temp.empty()) {
                        auto [h, idx] = temp.top();
                        if(h > max(heights[a], heights[b]) && idx > b) {
                            ans[originalIndex] = idx;
                            found = true;
                            break;
                        }
                        temp.pop();
                    }
                    if(!found) ans[originalIndex] = -1;
                }
                queryIndex--;
            }
        }
        
        return ans;
    }
};
*/





/*
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = heights.size();
        int q = queries.size();
        

        for(int i = 0; i < q; i++){
            int first = queries[i][0];
            int second = queries[i][1];
            if(first == second){
                ans.push_back(first);
                continue;
            }

            if(second == n-1){
                ans.push_back(second);
                continue;
            }

            if(heights[first] < heights[second] && first < second){
                ans.push_back(second);
                continue;
            }

            if(heights[second] < heights[first] && second < first){
                ans.push_back(first);
                continue;
            }

            int temp = max(first, second)+1;

            int maxElmQ = max(heights[first], heights[second]);
            priority_queue<pair<int,int>> pq;
            while(temp < n){
                if(maxElmQ < heights[temp]){
                    pq.push({heights[temp], temp});
                    break;
                }
                temp++;
            }

            if(pq.empty()){
                ans.push_back(-1);
            } else{
                ans.push_back(pq.top().second);
            }
        }

        return ans;
    }
};

*/
