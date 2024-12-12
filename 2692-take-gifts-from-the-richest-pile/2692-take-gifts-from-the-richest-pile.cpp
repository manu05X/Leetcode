class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap;

        for(int i = 0; i < gifts.size(); i++){
            maxHeap.push(gifts[i]);
        }

        while(k--){
            int x = maxHeap.top();
            maxHeap.pop();

            int sqrtX = sqrt(x);

            maxHeap.push(sqrtX);
        }


        long long ans = 0;
        while (!maxHeap.empty()) 
        {
            ans += maxHeap.top();
            maxHeap.pop();
        }

        return ans;
    }
};