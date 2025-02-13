class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);  
        cin.tie(NULL);
        
        int n = nums.size();

        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
        int count = 0;

        while(!pq.empty()){
            if(pq.top() >= k){
                break;
            }
            count++;

            long long first = pq.top(); 
            pq.pop();
            long long second = pq.top(); 
            pq.pop();

            long long newElm = min(first, second) * 2 + max(first, second);

            pq.push(newElm);
        }

        return count;
    }
};