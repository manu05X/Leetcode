class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q; // Queue for BFS
        q.push(start); 

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            // If the current index has value 0, we are done
            if (arr[current] == 0) {
                return true;
            }

            // Mark the current index as visited by setting it to -1
            // (as all values are non-negative, -1 indicates visited)
            if (arr[current] < 0) continue;

            int jumpForward = current + arr[current];
            int jumpBackward = current - arr[current];

            // Add valid indices to the queue
            if (jumpForward < n && arr[jumpForward] >= 0) {
                q.push(jumpForward);
            }
            if (jumpBackward >= 0 && arr[jumpBackward] >= 0) {
                q.push(jumpBackward);
            }

            // Mark current index as visited
            arr[current] = -1;
        }

        // If BFS ends without finding a 0, return false
        return false;
    }
};
