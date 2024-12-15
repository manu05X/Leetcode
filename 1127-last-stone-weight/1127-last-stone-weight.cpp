class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap(stones.begin(), stones.end());
        
        while (heap.size() > 1) {
            int first = heap.top();
            heap.pop();
            int second = heap.top();
            heap.pop();
            if (first != second) {
                heap.push(first - second);
            }
        }
        
        return heap.empty() ? 0: heap.top();
        
    }
};

/*
2,7,4,1,8,1

maxHeap
8,7,4,2,1,1

4,2,1,1,1
2,1,1,1
1,1,1
1

*/