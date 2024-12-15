class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());

        while(k--){
            int currElm = pq.top();
            pq.pop();

            //currElm = floor(currElm/2);

            pq.push(currElm - floor(currElm/2));

        }

        int ans = 0;
        while(!pq.empty()){
            ans += pq.top();
            pq.pop();
        }

        return ans;

    }
};