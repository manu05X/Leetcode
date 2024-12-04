
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0); // Array to store the final result
        vector<pair<int, int>> arr(n); // To store the number and its original index
        
        // Initialize the array of pairs with the numbers and their indices
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], i};
        }
        
        // Call the modified merge sort
        mergeSort(arr, 0, n - 1, result);
        return result;
    }

private:
    void mergeSort(vector<pair<int, int>>& arr, int start, int end, vector<int>& result) {
        if (start >= end) return; // Base case: single element
        
        int mid = start + (end - start) / 2;
        
        // Recursively sort left and right halves
        mergeSort(arr, start, mid, result);
        mergeSort(arr, mid + 1, end, result);
        
        // Merge the two halves
        merge(arr, start, mid, end, result);
    }

    void merge(vector<pair<int, int>>& arr, int start, int mid, int end, vector<int>& result) {
        int left = start;     // Pointer for the left half
        int right = mid + 1;  // Pointer for the right half
        vector<pair<int, int>> temp; // Temporary array for merging
        
        int countSmaller = 0; // Counts elements from the right half that are smaller
        
        // Merge left and right halves
        while (left <= mid && right <= end) {
            if (arr[left].first <= arr[right].first) {
                // Add the number of smaller elements to the result for the current index
                result[arr[left].second] += countSmaller;
                temp.push_back(arr[left]);
                ++left;
            } else {
                // Element from the right half is smaller, count it
                ++countSmaller;
                temp.push_back(arr[right]);
                ++right;
            }
        }
        
        // Add remaining elements from the left half
        while (left <= mid) {
            result[arr[left].second] += countSmaller;
            temp.push_back(arr[left]);
            ++left;
        }
        
        // Add remaining elements from the right half
        while (right <= end) {
            temp.push_back(arr[right]);
            ++right;
        }
        
        // Copy the merged elements back to the original array
        for (int i = start; i <= end; ++i) {
            arr[i] = temp[i - start];
        }
    }
};


/*
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        vector<int> indices(n);  // record the index. we are going to sort this array
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }
        // sort indices with their corresponding values in nums, i.e., nums[indices[i]]
        mergeSort(indices, 0, n, result, nums);
        return result;
    }

    void mergeSort(vector<int>& indices, int left, int right, vector<int>& result,
                   vector<int>& nums) {
        if (right - left <= 1) {
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(indices, left, mid, result, nums);
        mergeSort(indices, mid, right, result, nums);
        merge(indices, left, right, mid, result, nums);
    }

    void merge(vector<int>& indices, int left, int right, int mid, vector<int>& result,
               vector<int>& nums) {
        // merge [left, mid) and [mid, right)
        int i = left;  // current index for the left array
        int j = mid;   // current index for the right array
        // use temp to temporarily store sorted array
        vector<int> temp;
        while (i < mid && j < right) {
            if (nums[indices[i]] <= nums[indices[j]]) {
                // j - mid numbers jump to the left side of indices[i]
                result[indices[i]] += j - mid;
                temp.push_back(indices[i]);
                i++;
            } else {
                temp.push_back(indices[j]);
                j++;
            }
        }
        // when one of the subarrays is empty
        while (i < mid) {
            // j - mid numbers jump to the left side of indices[i]
            result[indices[i]] += j - mid;
            temp.push_back(indices[i]);
            i++;
        }
        while (j < right) {
            temp.push_back(indices[j]);
            j++;
        }
        // restore from temp
        move(temp.begin(), temp.end(), indices.begin() + left);
    }
};

*/