class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        ios_base::sync_with_stdio(false);         
        cin.tie(NULL);

        // Insert all the sticks into the min heap
        priority_queue<int,vector<int>, greater<int>> pq(sticks.begin(), sticks.end());

        int total = 0;
         // Continue this process until only one stick remains in the min heap
        while(pq.size()>1){
            // Extract the two smallest sticks from the min heap
            int firstStick = pq.top();
            pq.pop();

            int secondStick = pq.top();
            pq.pop();
            // Combine the two sticks
            int currCost = firstStick+secondStick;
            // Add the cost of combining the two sticks
            total += currCost;
            // Put the combined stick back into the min heap
            pq.push(currCost);
        }

        return total;
    }
};