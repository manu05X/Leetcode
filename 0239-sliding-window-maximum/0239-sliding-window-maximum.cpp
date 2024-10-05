class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int windowSize) {
         vector<int> result;
        // Initializing doubly ended queue for storing indices
        deque<int> window;
        // Let’s now return an empty list if nums is empty
        if (nums.size() == 0)
        {
            return result;
        }
        // If windowSize is greater than the array size,
        // set the windowSize to nums.size()
        if (windowSize > nums.size())
        {
            windowSize = nums.size();
        }

        // Find out first maximum in the first window
        for (int i = 0; i < windowSize; ++i)
        {
            // For every element, remove the previous smaller elements from window
            while (!window.empty() && nums[i] >= nums[window.back()])
            {
                window.pop_back();
            }
            // Add current element at the back of the queue
            window.push_back(i);
        }
        // Appending the largest element in the window to the result
        result.push_back(nums[window.front()]);
        
        for (int i = windowSize; i < nums.size(); ++i)
        {
            // remove all numbers that are smaller than current number
            // from the tail of list
            while (!window.empty() && nums[i] >= nums[window.back()])
            {
                window.pop_back();
            }

            // Remove first index from the window deque if
            // it doesn't fall in the current window anymore
            if (!window.empty() && window.front() <= i - windowSize)
            {
                window.pop_front();
            }
            // Add current element at the back of the queue
            window.push_back(i);
            result.push_back(nums[window.front()]);
        }
        return result;
    }
};