class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> firstElm = edges[0];
        vector<int> secondElm = edges[1];

        return (firstElm[0] == secondElm[0] || firstElm[0] == secondElm[1])
                ? firstElm[0] 
                : firstElm[1];
    }
};