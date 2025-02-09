class Solution {
public:
    int minDeletions(string s) {
        // Step 1: Store the frequency of each character
        vector<int> frequency(26, 0); // Since there are 26 lowercase letters
        for (char ch : s) {
            frequency[ch - 'a']++; // Increment count for each character
        }
        
        // Step 2: Use a max-heap (priority queue) to store frequencies in descending order
        priority_queue<int> pq;
        for (int freq : frequency) {
            if (freq > 0) {
                pq.push(freq); // Add only non-zero frequencies
            }
        }
        
        int deleteCount = 0; // Count of deletions needed
        
        // Step 3: Process the heap to ensure unique frequencies
        while (pq.size() > 1) { // Keep going until only one unique frequency remains
            int topElement = pq.top();
            pq.pop();

            // Step 4: If two highest frequencies are the same, reduce one
            if (!pq.empty() && topElement == pq.top()) { // Check the next highest frequency
                // Decrement the popped frequency and push it back if it's still positive
                if (topElement - 1 > 0) {
                    pq.push(topElement - 1);
                }
                deleteCount++; // Increment deletion count
            }
        }
        
        return deleteCount; // Return the minimum deletions required
    }
};