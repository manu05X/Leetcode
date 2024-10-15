class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        /*
        [4,2,1,3]
        */
        ios_base::sync_with_stdio(false);  
        cin.tie(NULL);

        int n = arr.size();
        int minDiff = INT_MAX;
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());

        for(int i = 0; i < n-1; i++)
        {
            minDiff = min(minDiff, arr[i+1]-arr[i]);
        }

        for(int i = 0; i < n-1; i++){
            if(minDiff == (arr[i+1]-arr[i]))
            {
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};