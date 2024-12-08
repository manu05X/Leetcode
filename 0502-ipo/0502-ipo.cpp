class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> projects;

        // Step 1: Pair each project with its capital and profit
        for(int i = 0; i < n; i++) {
            projects.push_back({capital[i], profits[i]});
        }

        // Step 2: Sort projects by the capital required in ascending order
        sort(projects.begin(), projects.end());

        // Step 3: Max-heap to store profits of feasible projects
        priority_queue<int> heap;
        int l = 0; // Pointer to iterate through projects

        // Step 4: Perform up to 'k' project selections
        for(int r = 0; r < k; r++) {
            // Add all feasible projects to the heap (those whose capital requirement is <= current `w`)
            while(l < n && projects[l].first <= w) {
                heap.push(projects[l].second); // Add profit to the heap
                l++;
            }

            // If no feasible projects are left, return the current capital
            if(heap.empty()) {
                return w;
            }

            // Select the project with the maximum profit (top of the heap)
            w += heap.top();
            heap.pop();
        }

        // Return the final maximized capital after selecting up to 'k' projects
        return w;
    }
};