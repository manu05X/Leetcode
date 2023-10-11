class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        vector<int> starts;
        vector<int> ends;
        
        for (vector<int>& flower : flowers) {
            starts.push_back(flower[0]);
            ends.push_back(flower[1] + 1);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        vector<int> ans;
        
        for (int person : people) {
            // i  = 1, 2, 3, 4
            int i = upper_bound(starts.begin(), starts.end(), person) - starts.begin();
            //j = 0, 0, 1, 2 
            int j = upper_bound(ends.begin(), ends.end(), person) - ends.begin();
            ans.push_back(i - j);
        }
        
        return ans;
    }
};


/*

upper_bound (ForwardIterator first, ForwardIterator last, const T& val);
upper_bound= function returns an iterator that points to the first value that is greater than the specified value, or returns the iterator pointing to the (end + 1) index if no such element is found.

upper_bound= function can be used to find the last occurrence of an element in an array.

flowers:{{1, 6}, {3, 7}, {9, 12}, {4, 13}}
people:{2, 3, 7, 11}
starts:{1, 3, 4, 9}
ends:{7, 8, 13, 14}

i = 1, 2, 3, 4
j = 0, 0, 1, 2

ans:{1, 2, 2, 2}


*/
