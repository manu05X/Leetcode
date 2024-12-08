class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects;

        for(int i = 0; i < n; i++){
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());
        priority_queue<int> heap;
        int l = 0;

        for(int r = 0; r < k; r++){
            while(l < n && projects[l].first <= w){
                heap.push(projects[l].second);
                l++;
            }

            if(heap.size() == 0){
                return w;
            }

            w += heap.top();
            heap.pop();
        }

        return w;
    }
};